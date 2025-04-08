/* Copyright 2024 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */
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
               *mpph26xenc,
               *mp4mux,
               *sink,
               *h26xparse,
               *capabilities;
};

struct GSTOBJ {
    struct _GSTHANDLE handle;
    struct _GSTELES elements;
};

static struct GSTOBJ *gstobj = NULL;
static bool g_quit = false;

/**
 * Gstreamer pipeline message bus callback function
 */
static gboolean bus_call(GstBus *bus, GstMessage *msg, gpointer data) {
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
        printf("Error: %s\n", error->message);
        g_error_free(error);
        g_main_loop_quit(loop);
        break;
    default:
        break;
    }
    return true;
}

/**
 * This thread is used to calculate the time spent
 */
static void *timing_thread(void *arg) {
    static struct timeval t_start, t_current;
    int duration = 0;
    int hour = 0, min = 0, sec = 0;

    /* get start timestamp */
    gettimeofday(&t_start, NULL);
    printf(" starting \n\n");

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

/**
 * signal handler function
 */
static void sig_handle(int signal) {
    printf("\n\n\r\033[k");
    if (gstobj != NULL) {
        gst_element_send_event(gstobj->handle.pipeline, gst_event_new_eos());
        usleep(50000);
        g_main_loop_quit(gstobj->handle.loop);
    }
    g_quit = true;
    sleep(1);
}

/**
 * initialize gst object
 */
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

/**
 * Create the elements 
 */
bool make_gst_elements(struct _GSTELES *elements , struct _Params *params) {
    
    if (elements == NULL || params == NULL )
        return false;

    /* Initialization of elements */
    elements->source          = gst_element_factory_make("videotestsrc", "_source");
    elements->mp4mux          = gst_element_factory_make("mp4mux", "_mp4mux");
    elements->sink            = gst_element_factory_make("filesink", "_sink");
    elements->capabilities    = gst_element_factory_make("capsfilter", "_incaps");  

    if(strcmp(params->h26x, "h264") == 0)
    {
        elements->h26xparse       = gst_element_factory_make("h264parse", "_h26xparse");
        elements->mpph26xenc      = gst_element_factory_make("mpph264enc", "_mpph26xenc");
        printf("\033[34m You have chosen %s:@%dfps to save as MP4file\n \033[0m",params->h26x,params->framrate);
    }
    else if(strcmp(params->h26x, "h265") == 0)
    {
        elements->h26xparse       = gst_element_factory_make("h265parse", "_h26xparse");
        elements->mpph26xenc      = gst_element_factory_make("mpph265enc", "_mpph26xenc");
        printf("\033[34m You have chosen %s:@%dfps to save as MP4file\n \033[0m",params->h26x,params->framrate);     
    }
    else
    {   
        printf("\n please input h264 or h265 \n");
        return false;
    }

    return true;
}

/**
 * check if element was created successfully
 */
bool check_gst_elements(struct _GSTELES *elements) {
    
    if (elements == NULL)
    return false;

    /* check elements */
    bool isErr = false;

    if (!elements->h26xparse|| !elements->mp4mux || 
        !elements->mpph26xenc || !elements->sink ||
        !elements->source ||  !elements->capabilities) {
        isErr = true;
    }
    if (isErr)
        printf("Element Creation failure.\n");

    return !isErr;
}

/**
 * config elements
 */
bool config_gst_elements(struct _Params *params, struct _GSTELES *elements) {
    GstCaps *caps;

    if (params == NULL || elements == NULL)
        return false;

    /* Set elements params */
    caps = gst_caps_new_simple("video/x-raw",
                               "format", G_TYPE_STRING, "NV12",
                               "width", G_TYPE_INT, params->width,
                               "height", G_TYPE_INT, params->height,
                               "framerate", GST_TYPE_FRACTION, params->framrate, 1,
                               NULL);
    g_object_set(G_OBJECT(elements->capabilities), "caps", caps, NULL);
    gst_caps_unref(caps);

    /* Set the properties of the source element */
    g_object_set(elements->source, "num-buffers", params->numbuffer, NULL);
    g_object_set(elements->source, "pattern", params->pattern, NULL);

    /* Set the properties of the sink element*/
    g_object_set(elements->sink, "location", params->file, NULL);

    return true;
}

/**
 * link elements
 */
bool link_gst_elements(struct _GSTELES *elements, GstElement *pipeline) {
    
    if (elements == NULL || pipeline == NULL)
        return false;

    /* Add elements to pipeline and link elements */
        gst_bin_add_many(GST_BIN(pipeline), elements->source, elements->capabilities,
                                 elements->mpph26xenc, elements->h26xparse,elements->mp4mux,elements->sink, NULL);

        if (!gst_element_link_many(elements->source, elements->capabilities,
                                 elements->mpph26xenc, elements->h26xparse,elements->mp4mux,elements->sink, NULL)) {
            printf("Unable to link the elements\n");
            return false;
        }
    return true;
}

/**
 * Play the pipeline
 */
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
    
    return true;
}

/**
 * Release gstreamer pipeline
 */
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
    
    /* Ctrl+c handler */
    signal(SIGINT, sig_handle);

    /*Apply for heap space*/
    gstobj = (struct GSTOBJ *)malloc(sizeof(struct GSTOBJ));
    memset(gstobj, 0, sizeof(struct GSTOBJ));

    memset(&params, 0, sizeof(params));
    ret = parse_parameter(&params, argc, argv);
    if(! ret)
        return -1;

    /* Initialization of gstreamer */
    ret = initialize_gst(argc, argv, &gstobj->handle);
    if (! ret) {
        printf("\n Initialization failed \n");
        goto err_release;
    }

    /* Create elements */
    ret = make_gst_elements(&gstobj->elements, &params);
    if (! ret) {
        printf("\n Make elements failed\n\n");
        goto err_release;
    }

    /* Check creation of elements */
    ret = check_gst_elements(&gstobj->elements);
    if (! ret) {
        printf("\n Elements error in check \n");
        goto err_release;
    }

    /* Configuration elements */
    ret = config_gst_elements(&params, &gstobj->elements);
    if (! ret) {
        printf("\n Config elements failed \n");
        goto err_release;
    }

    /* Link elements into pipeline */
    ret = link_gst_elements( &gstobj->elements,gstobj->handle.pipeline);
    if (! ret) {
        printf("\n Link elements failed \n");
        goto err_release;
    }

    /* Play the pipeline */
    ret = play_gst_pipeline(&gstobj->handle);
    if (! ret) {
        printf(" \n Play the pipeline failed \n");
        goto err_release;
    }

    /* Create loop, keep listen for pipeline event */
    g_main_loop_run(gstobj->handle.loop);

err_release:
    /* Release gst pipeline*/
    release_gst(&gstobj->handle);
    free(gstobj);
    if (! ret)
        return -1;

    printf("Exit\n");
    return 0;
}
