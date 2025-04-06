/* Copyright 2024 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <gst/gst.h>
#include "parameter_parser.h"

static struct _GSTOBJ *gstobj;
static bool g_quit = false;

struct _GSTHANDLE {
    GMainLoop *loop;
    GstBus *bus;
    GstElement *pipeline;
    GstMessage *msg;
};

struct _GSTELES {
    GstElement *source,
               *demuxer,
               *parser,
               *decoder,
               *sink,
               *capabilities,
               *filter,
               *videoscale,
               *videorate;
};

struct _GSTOBJ {
    struct _GSTHANDLE handle;
    struct _GSTELES elements;
};

static void on_pad_added(GstElement *element, GstPad *pad, gpointer data) {
    GstPad *sinkpad;
    GstElement *parser = (GstElement*)data;
    GstCaps *caps;
    gchar *padname;

    padname = gst_pad_get_name(pad);
    g_print("New pad '%s' detected.\n", padname);
    g_free(padname);

    caps = gst_pad_query_caps(pad, NULL);
    if (!gst_caps_is_fixed(caps)) {
        g_printerr("Pad caps are not fixed.\n");
        return;
    }
    /* Create an element to connect the src pad of the demuxer to the sink pad of the parser */
    sinkpad = gst_element_get_static_pad(parser, "sink");
    if (GST_PAD_IS_LINKED(sinkpad)) {
        g_printerr("Parser sink pad is already linked.\n");
        return;
    }
    if (gst_pad_link(pad, sinkpad) != GST_PAD_LINK_OK) {
        g_printerr("Failed to link demuxer and parser.\n");
    }
    gst_object_unref(sinkpad);
    gst_caps_unref(caps);
}

static void sig_handle(int signal) {
    printf("\n\n\r\033[k");
    if (gstobj != NULL)
    {
         g_main_loop_quit(gstobj->handle.loop);
    }
    g_quit = true;
    sleep(1);
}

/* Initialization of gstreamer */
bool initialize_gst(int argc, char **argv, struct _GSTHANDLE *handle,struct _GSTELES *elements,struct _Params *params) {
    if (handle == NULL)
        return false;
    GstCaps *caps;
    gst_init(&argc, &argv);
    handle->loop = g_main_loop_new(NULL, FALSE);

    /* Create a new pipeline */
    handle->pipeline = gst_pipeline_new("_pipeline");
    if (!handle->pipeline)
        return false;

    /* Creating Elements */
    handle->pipeline = gst_pipeline_new("mp4-player");
    elements->source = gst_element_factory_make("filesrc", "file-source");
    elements->demuxer = gst_element_factory_make("qtdemux", "demuxer");
    elements->decoder = gst_element_factory_make("mppvideodec", "video-decoder");
    elements->sink = gst_element_factory_make("waylandsink", "video-sink");
    elements->videorate = gst_element_factory_make("videorate", "videorate");
    elements->capabilities = gst_element_factory_make("capsfilter", "capsfilter");
    elements->videoscale = gst_element_factory_make("videoscale", "videoscale");
    if(strcmp(params->h26x,"h264") ==0 )
    {
        elements->parser = gst_element_factory_make("h264parse", "h264parse");
        /*Check if the element was successfully created*/
        if( !elements->source || !elements->demuxer || !elements->decoder || !elements->sink ||
            !elements->parser || !elements->videorate ||  !elements->capabilities )
        {
            g_printerr("Failed to create elements. Exiting.\n");
            return false;
        }

        /*Set the frame rate for playback*/
        caps = gst_caps_new_simple("video/x-raw",
                                "format", G_TYPE_STRING, "NV12",
                                "framerate", GST_TYPE_FRACTION, params->framerate, 1,
                                NULL);
    }
    else if(strcmp(params->h26x,"h265") ==0)
    {
        elements->parser = gst_element_factory_make("h265parse", "h265parse");   
        /*Check if the element was successfully created*/
        if( !elements->source || !elements->demuxer || !elements->decoder || !elements->sink ||
            !elements->parser || !elements->videorate ||  !elements->capabilities )
        {
            g_printerr("Failed to create elements. Exiting.\n");
            return false;
        }

        /*Set the frame rate for playback*/
        caps = gst_caps_new_simple("video/x-raw",
                                "format", G_TYPE_STRING, "NV12",
                                "framerate", GST_TYPE_FRACTION, params->framerate, 1,
                                NULL);
    }
    else
    {   
        printf("\033[34m please input h264 or h265\n \033[0m");
        return false;
    }
    printf("\033[34m You have chosen %s:@%dfps to play \n \033[0m",params->h26x,params->framerate);


    g_object_set(G_OBJECT(elements->capabilities), "caps", caps, NULL);
    gst_caps_unref(caps);

    /* Set filesrc Path */
    g_object_set(G_OBJECT(elements->source), "location", params->location, NULL);

    /* Add elements to pipeline*/
    gst_bin_add_many(GST_BIN(handle->pipeline), elements->source, elements->demuxer,
                        elements->parser, elements->decoder  ,  elements->videorate , 
                        elements->videoscale, elements->capabilities , elements->sink ,
                        NULL);

    /* link elements to pipeline*/
    if((  gst_element_link(elements->source, elements->demuxer) &&
            gst_element_link(elements->parser, elements->decoder)&&
            gst_element_link(elements->decoder, elements->videorate)&&
            gst_element_link(elements->videorate, elements->videoscale)&&
            gst_element_link(elements->videoscale, elements->capabilities)&&
            gst_element_link(elements->capabilities, elements->sink)) != TRUE)
        {
            g_printerr("Failed to link elements. Exiting.\n");
            return false;
        }

    /* Set the callback function for the "demuxer" to receive stream data */
    g_signal_connect(elements->demuxer, "pad-added", G_CALLBACK(on_pad_added), elements->parser);
    
    return true;
}

/* This thread is used to calculate the time spent */
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

int main(int argc, char *argv[]) {

    gboolean ret; 
    struct _Params params;
    bool pret;

    signal(SIGINT, sig_handle);

    gstobj = (struct _GSTOBJ *)malloc(sizeof(struct _GSTOBJ));
    memset(gstobj, 0, sizeof(struct _GSTOBJ));
    memset(&params, 0, sizeof(params));

    pret = parse_parameter(&params, argc, argv);
    if(! pret)
        return -1;

    /*Initialization Gst*/
    ret = initialize_gst(argc, argv, &gstobj->handle,&gstobj->elements,&params);
    if(! ret)
    {
        printf("\n Initialization Gst fail \n");
        goto err_release;
    }

    /* Play the pipeline */
    ret = play_gst_pipeline(&gstobj->handle);
    if (! ret) {
        printf(" \n Play the pipeline failed \n");
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

