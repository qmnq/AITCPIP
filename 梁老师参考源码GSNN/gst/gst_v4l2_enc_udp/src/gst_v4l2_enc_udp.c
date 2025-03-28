/* Copyright 2023 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */
#include <stdio.h>
#include <stdint.h>
#include <gst/gst.h>
#include <signal.h>
#include <getopt.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include "parameter_parser.h"

struct _GSTHANDLE {
    GMainLoop *loop;
    GstBus *bus;
    GstElement *pipeline;
};

struct _GSTELES {
    GstElement *source,
               *tee,
               *queue_1,
               *queue_2,
               *encode,
               *parse,
               *payload,
               *capabilities,
               *sink_1,
               *sink_2;
};

struct _GSTOBJ {
    struct _GSTHANDLE handle;
    struct _GSTELES elements;
};

static struct _GSTOBJ *gstobj;
static bool g_quit = false;

static gboolean bus_call(GstBus *bus, GstMessage *msg,gpointer data) {
    GMainLoop *loop = (GMainLoop *)data;
    gchar  *debug;
    GError *error;

    switch (GST_MESSAGE_TYPE(msg)) {
    case GST_MESSAGE_EOS:
        g_print("End of stream\n");
        g_main_loop_quit(loop);
        break;

    case GST_MESSAGE_ERROR:
        gst_message_parse_error(msg, &error, &debug);
        g_free(debug);
        g_printerr("Error: %s\n", error->message);
        g_error_free(error);
        g_main_loop_quit(loop);
        break;

    default:
        break;
    }

    return true;
}

/* This thread is used to calculate the time spent */
static void *timing_thread(void *arg) {
    static struct timeval t_start, t_current;
    int duration = 0;
    int hour = 0, min = 0, sec = 0;

    /* get start timestamp */
    gettimeofday(&t_start, NULL);
    printf("Ready for starting\n\n");

    while (!g_quit) {
        /* get the current time */
        gettimeofday(&t_current, NULL);
        
        /* calculate thread duration time */
        duration = (t_current.tv_sec - t_start.tv_sec);
        hour     = duration / 3600;
        min      = duration / 60 - (hour * 60);
        sec      = duration % 60;

        printf("-- Duration %02d:%02d:%02d --", hour, min, sec);

        /* Clear the read-write buffer */
        fflush(stdout);
        /* Clear content from cursor to end of line */
        printf("\r\033[k");
        sleep(1);
    }
    
    printf("Stoping\n");
    return (void *)0;
}

static void sig_handle(int signal) {
    printf("\n\n\r\033[k");
    if (gstobj != NULL)
        g_main_loop_quit(gstobj->handle.loop);

    g_quit = true;
    sleep(1);
}

bool initialize_gst(int argc, char **argv, struct _GSTHANDLE *handle) {
    if (handle == NULL)
        return false;

    /* Initialization of gstreamer */
    gst_init(&argc, &argv);
    handle->loop = g_main_loop_new(NULL, FALSE);

    /* Create a new pipeline */
    handle->pipeline = gst_pipeline_new("_pipeline");
    if (!handle->pipeline)
        return false;

    return true;
}

bool make_gst_elements(enum _Mode mode, struct _GSTELES *elements) {
    if (elements == NULL)
        return false;

    /* Initialization of elements */
    elements->source        = gst_element_factory_make("v4l2src", "_src");
    elements->capabilities  = gst_element_factory_make("capsfilter", "_incaps");
    elements->queue_1       = gst_element_factory_make("queue", "_queue_1");

    if (mode == M_SAVE || mode == M_UDP || mode == M_DIS_SAVE)
        elements->encode    = gst_element_factory_make("mpph264enc", "_encode");

    switch (mode) {
    case M_DISPLAY:
        elements->sink_1    = gst_element_factory_make("autovideosink", "_sink_1");
        break;

    case M_SAVE:
        elements->sink_1    = gst_element_factory_make("filesink", "_sink_1");
        break;

    case M_UDP:
        elements->parse     = gst_element_factory_make("h264parse", "_parse");
        elements->payload   = gst_element_factory_make("rtph264pay", "_payload");
        elements->sink_1    = gst_element_factory_make("udpsink", "_sink_1");
        break;

    case M_DIS_SAVE:
        elements->tee       = gst_element_factory_make("tee", "_tee");
        elements->queue_2   = gst_element_factory_make("queue", "_queue_2");
        elements->sink_1    = gst_element_factory_make("filesink", "_sink_1");
        elements->sink_2    = gst_element_factory_make("autovideosink", "_sink_2");
        break;

    default:
        return false;
    }

    return true;
}

bool check_gst_elements(enum _Mode mode, struct _GSTELES *elements) {
    /* check elements */
    bool isErr = false;

    if (!elements->source || !elements->capabilities || 
        !elements->queue_1 || !elements->sink_1) {
        isErr = true;
    }

    switch (mode) {
    case M_DISPLAY:
        break;

    case M_SAVE:
        if (!elements->encode)
            isErr = true;
        break;

    case M_UDP:
        if (!elements->encode || !elements->parse || !elements->payload)
            isErr = true;
        break;

    case M_DIS_SAVE:
        if (!elements->encode || !elements->tee ||
            !elements->sink_2 || !elements->queue_2) {
            isErr = true;
        }
        break;

    default:
        isErr = true;
        break;
    }

    if (isErr)
        g_printerr("Element Creation failure.\n");

    return !isErr;
}

bool config_gst_elements(struct _Params *params, struct _GSTELES *elements) {
    GstCaps *caps;

    if (params == NULL || elements == NULL)
        return false;

    /* Set elements params */
    g_object_set(G_OBJECT(elements->source), "device", params->device, NULL);
    g_object_set(G_OBJECT(elements->source), "io-mode", 4, NULL);

    caps = gst_caps_new_simple("video/x-raw",
                               "format", G_TYPE_STRING, "NV12",
                               "width", G_TYPE_INT, params->width,
                               "height", G_TYPE_INT, params->height,
                               NULL);
    g_object_set(G_OBJECT(elements->capabilities), "caps", caps, NULL);
    gst_caps_unref(caps);

    /* Set the level and profile of encoder in the save mode or udp mode */
    if (params->mode == M_SAVE || params->mode == M_UDP ||
        params->mode == M_DIS_SAVE) {
        g_object_set(G_OBJECT(elements->encode), "level", 51, NULL);
    }

    switch (params->mode) {
    case M_DISPLAY:
        break;

    case M_SAVE:
        /* Set the saving location of the save mode */
        g_object_set(G_OBJECT(elements->sink_1), "location", params->file, NULL);
        break;

    case M_UDP:
        /* Set the host address of the udp mode */
        g_object_set(G_OBJECT(elements->sink_1), "host", params->host, NULL);
        g_object_set(G_OBJECT(elements->sink_1), "port", params->port, NULL);
        break;

    case M_DIS_SAVE:
        /* Set the saving location of the save mode */
        g_object_set(G_OBJECT(elements->sink_1), "location", params->file, NULL);
        break;

    default:
        return false;
    }

    return true;
}

bool link_gst_elements(enum _Mode mode,
                       struct _GSTELES *elements,
                       GstElement *pipeline) {
    if (elements == NULL || pipeline == NULL)
        return false;

    /* Add elements to pipeline and link elements */
    switch (mode) {
    case M_DISPLAY:
        printf("Mode --> Display\n");
        gst_bin_add_many(GST_BIN(pipeline), elements->source, elements->capabilities,
                                 elements->queue_1, elements->sink_1, NULL);

        if (!gst_element_link_many(elements->source, elements->capabilities,
                                 elements->queue_1, elements->sink_1, NULL)) {
            printf("Unable to link the elements\n");
            return false;
        }
        break;

    case M_SAVE:
        printf("Mode --> Save\n");
        gst_bin_add_many(GST_BIN(pipeline), elements->source, elements->capabilities,
                                 elements->queue_1, elements->encode,
                                 elements->sink_1, NULL);

        if (!gst_element_link_many(elements->source, elements->capabilities,
                                 elements->queue_1, elements->encode,
                                 elements->sink_1, NULL)) {
            printf("Unable to link the elements\n");
            return false;
        }
        break;

    case M_UDP:
        printf("Mode --> UDP\n");
        gst_bin_add_many(GST_BIN(pipeline), elements->source, elements->capabilities,
                                 elements->queue_1, elements->encode,
                                 elements->parse, elements->payload, 
                                 elements->sink_1, NULL);

        if (!gst_element_link_many(elements->source, elements->capabilities,
                                 elements->queue_1, elements->encode,
                                 elements->parse, elements->payload,
                                 elements->sink_1, NULL)) {
            printf("Unable to link the elements\n");
            return false;
        }
        break;

    case M_DIS_SAVE:
        printf("Mode --> DIS-SAVE\n");

        gst_bin_add_many(GST_BIN(pipeline), elements->source, elements->capabilities,
                                 elements->tee, elements->queue_1,
                                 elements->encode, NULL);

        gst_bin_add_many(GST_BIN(pipeline),
                                 elements->sink_1, elements->queue_2,
                                 elements->sink_2, NULL);

        if (!gst_element_link_many(elements->source, elements->capabilities,
                                 elements->tee, NULL)) {
            printf("Unable to link tee\n");
            return false;
        }

        if (!gst_element_link_many(elements->tee, elements->queue_1,
                                 elements->encode, elements->sink_1,
                                   NULL)) {
            printf("Unable to link save queue\n");
            return false;
        }

        if (!gst_element_link_many(elements->tee, elements->queue_2,
                                 elements->sink_2, NULL)) {
            printf("Unable to link display queue\n");
            return false;
        }

        break;

    default:
        return false;
    }

    return true;
}

bool play_gst_pipeline(struct _GSTHANDLE *handle) {
    pthread_t id;
    gboolean ret;

    if (handle == NULL)
        return false;

    /* Get pipeline message bus and monitoring messages */
    handle->bus = gst_pipeline_get_bus(GST_PIPELINE(handle->pipeline));
    gst_bus_add_watch(handle->bus, bus_call, handle->loop);
    gst_object_unref(handle->bus);

    /* Start the pipeline */
    ret = gst_element_set_state(handle->pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_ASYNC || ret == GST_STATE_CHANGE_SUCCESS) {
        /* Crete timing thread */
        if (pthread_create(&id, NULL, timing_thread, NULL)) {
            printf("Creating timing thread failed !\n");
            return false;
        }
        pthread_detach(id);
    }

    g_main_loop_run(handle->loop);

    return true;
}

void release_gst(struct _GSTHANDLE *handle) {
    /* clean up */
    gst_element_set_state(handle->pipeline, GST_STATE_NULL);

    /* Release gst pipeline*/
    gst_object_unref(GST_OBJECT(handle->pipeline));

    /* Quit loop */
    g_main_loop_unref(handle->loop);
}

int main(int argc, char **argv) {
    bool ret;
    struct _Params params;

    signal(SIGINT, sig_handle);

    gstobj = (struct _GSTOBJ *)malloc(sizeof(struct _GSTOBJ));
    memset(gstobj, 0, sizeof(struct _GSTOBJ));
    memset(&params, 0, sizeof(params));

    ret = parse_parameter(&params, argc, argv);
    if(! ret)
        return -1;

    /* Initialization of gstreamer */
    ret = initialize_gst(argc, argv, &gstobj->handle);
    if (! ret) {
        perror("Initialization failed");
        goto err_release;
    }

    /* Create elements */
    ret = make_gst_elements(params.mode, &gstobj->elements);
    if (! ret) {
        perror("Make elements failed");
        goto err_release;
    }

    /* Check creation of elements */
    ret = check_gst_elements(params.mode, &gstobj->elements);
    if (! ret) {
        perror("Elements error in check");
        goto err_release;
    }

    /* Configuration elements */
    ret = config_gst_elements(&params, &gstobj->elements);
    if (! ret) {
        perror("Config elements failed");
        goto err_release;
    }

    /* Link elements into pipeline */
    ret = link_gst_elements(params.mode, &gstobj->elements,
                            gstobj->handle.pipeline);
    if (! ret) {
        perror("Link elements failed");
        goto err_release;
    }

    /* Play the pipeline */
    ret = play_gst_pipeline(&gstobj->handle);
    if (! ret) {
        perror("Play the pipeline failed");
        goto err_release;
    }

err_release:
    /* Release gst pipeline*/
    release_gst(&gstobj->handle);
    if (! ret)
        return -1;

    printf("Exit\n");
    return 0;
}
