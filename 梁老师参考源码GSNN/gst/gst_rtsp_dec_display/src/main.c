/* Copyright 2023 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <gst/gst.h>

#include "parameter_parser.h"

struct CameraAttributes {
    const char *rtsp_url;
    bool show_fps;
};

struct GstHandle {
    GstElement *pipeline;
};

struct GstEles {
    GstElement *source;
    GstElement *depay;
    GstElement *parse;
    GstElement *decode;
    GstElement *videosink;
};

typedef struct _GstObj {
    struct GstEles elements;
    struct GstHandle handle;

    struct CameraAttributes *camera;
} GstObj;

/* gst object */
GstObj *g_gstobj   = NULL;

/* GLib's Main Loop, listen for pipeline event*/
GMainLoop *main_loop;

/**
 * initialize gst object
 */
GstObj *gst_obj_init(struct _Params *params)
{
    GstObj *gstobj = NULL;

    if (params == NULL) {
        return NULL;
    }

    gstobj = (GstObj *)malloc(sizeof(GstObj));
    if (gstobj == NULL) {
        return NULL;
    }

    gstobj->camera = (struct CameraAttributes *)malloc(sizeof(struct CameraAttributes));
    if (gstobj->camera == NULL) {
        free(gstobj);
        gstobj = NULL;

        return NULL;
    }

    gstobj->camera->rtsp_url = params->url;
    gstobj->camera->show_fps = params->show_fps;

    return gstobj;
}

/**
 * release gst object
 */
void gst_obj_release(GstObj *gstobj)
{
    if (gstobj == NULL) {
        return;
    }

    if (gstobj->camera != NULL) {
        free(gstobj->camera);
        gstobj->camera = NULL;
    }

    free(gstobj);
    gstobj = NULL;
}

static void cb_new_rtspsrc_pad(GstElement *element, GstPad *pad, gpointer data)
{
    GstCaps *pad_caps = NULL;
    GstPad *sink_pad = NULL;

    sink_pad = gst_element_get_static_pad(GST_ELEMENT(data), "sink");

    /* If our converter is already linked, we have nothing to do here */
    if(gst_pad_is_linked(sink_pad))
        goto release;

    /* Get the new pad's type */
    pad_caps = gst_pad_get_current_caps(pad);

    /* Attempt the link */
    gst_pad_link(pad, sink_pad);

release:
    /* Unreference the new pad's caps, if we got them */
    if(pad_caps != NULL)
        gst_caps_unref(pad_caps);

    /* Unreference the sink pad */
    gst_object_unref(sink_pad);
}

/**
 * Gstreamer pipeline message bus callback function
 */
static gboolean bus_cb_func(GstBus *bus, GstMessage *msg, gpointer data)
{
    gchar  *debug;
    GError *error;

    /* judege gstreamer message type */
    switch (GST_MESSAGE_TYPE(msg)) {
        /* End of stream */
        case GST_MESSAGE_EOS:
            g_print("End of stream\n");
            g_main_loop_quit(main_loop);
            break;

        /* Error occured on the pipeline */
        case GST_MESSAGE_ERROR:
            gst_message_parse_error(msg, &error, &debug);
            g_free(debug);
            g_printerr("Error: %s\n", error->message);
            g_error_free(error);
            g_main_loop_quit(main_loop);
            break;
        default:
            break;
    }

    return true;
}

/**
 * Create gstreamer pipeline
 */
int gst_create_pipeline(int argc, char **argv, GstObj *gstobj)
{
    int status = 0;

    /* Initialization of gstreamer */
    gst_init(&argc, &argv);

    /* Create empty pipeline */
    gstobj->handle.pipeline = gst_pipeline_new("pipeline");
    if (!gstobj->handle.pipeline) {
        status = -1;
    }

    return status;
}

/**
 * Configuration gstreamer pipeline
 */
int gst_config_pipeline(GstObj *gstobj)
{
    int status = 0;
    struct GstEles *elements = &gstobj->elements;
    GstElement *waylandsink = NULL;

    /* Create the elements */
    elements->source        = gst_element_factory_make("rtspsrc", "_rtspsrc");
    elements->depay         = gst_element_factory_make("rtph264depay", "_rtph264depay");
    elements->parse         = gst_element_factory_make("h264parse", "_h264parse");
    elements->decode        = gst_element_factory_make("mppvideodec", "_mppvideodec");
    
    /* The screen displays framerate information */
    if(gstobj->camera->show_fps) {
        elements->videosink = gst_element_factory_make("fpsdisplaysink", "_fpsdisplaysink");
        waylandsink = gst_element_factory_make("waylandsink", "_waylandsink");
    } else {
        elements->videosink = gst_element_factory_make("waylandsink", "_waylandsink");
    }

    /* check if element was created successfully */
    if (!elements->source || !elements->depay || !elements->parse
        || !elements->decode || !elements->videosink) {
        status = -1;
        goto err_leave;
    }

    /*
     * Set Gst pipeline elements params
     */
    g_object_set(G_OBJECT(elements->source), "location", gstobj->camera->rtsp_url, NULL);
    g_signal_connect(elements->source, "pad-added", G_CALLBACK(cb_new_rtspsrc_pad), elements->depay);

    if(gstobj->camera->show_fps) {
        g_object_set(G_OBJECT(elements->videosink),
                    "video-sink", waylandsink,
                    "signal-fps-measurements", TRUE,
                    "text-overlay", FALSE,
                    NULL);
    }

    g_object_set(G_OBJECT(elements->videosink), "sync", FALSE, NULL);

    /* Add elements to pipeline and link elements */
    gst_bin_add_many(GST_BIN(gstobj->handle.pipeline),
                     elements->source,
                     elements->depay,
                     elements->parse,
                     elements->decode,
                     elements->videosink,
                     NULL);

    if (gst_element_link_many(elements->depay,
                              elements->parse,
                              elements->decode,
                              elements->videosink, NULL) != TRUE) {
        status = -1;
        goto err_leave;
    }

err_leave:
    return status;
}

/**
 * Play the pipeline
 */
int gst_exec(GstObj *gstobj, GMainLoop* loop)
{
    int status = 0, ret = -1;
    GstBus *bus;

    /* Get appsink pipeline message bus and monitoring messages */
    bus = gst_pipeline_get_bus(GST_PIPELINE(gstobj->handle.pipeline));
    gst_bus_add_watch(bus, bus_cb_func, loop);
    gst_object_unref(bus);

    /* Change pipeline status to playing */
    ret = gst_element_set_state(gstobj->handle.pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        status = -1;
        goto err_leave;
    }

err_leave:
    return status;
}

/**
 * Release gstreamer pipeline
 */
void gst_release_pipeline(GstObj *gstobj)
{
    /* Set null state to gst pipeline */
    gst_element_set_state(gstobj->handle.pipeline, GST_STATE_NULL);

    /* Release gst pipeline*/
    gst_object_unref(GST_OBJECT(gstobj->handle.pipeline));
}

/**
 * signal handler function
 */
static void sig_handle(int signal)
{
    if(g_gstobj != NULL) {
        g_main_loop_quit(main_loop);
    }
}

int main(int argc, char *argv[])
{
    struct _Params params;
    int ret = -1;
    int status = -1;

    memset(&params, 0, sizeof(params));
    if (parse_parameter(&params, argc, argv) == false) {
        printf("Please try --help to see usage.\n");
        exit(2);
    }

    /* Ctrl+c handler */
    signal(SIGINT, sig_handle);

    /* Create new main loop */
    main_loop = g_main_loop_new(NULL, FALSE);

    /* Initialize gstreamer object */
    g_gstobj = gst_obj_init(&params);
    if (g_gstobj == NULL) {
        printf("--> main: Initialize gstreamer object failed.\n");
        exit(-1);
    }
    printf("--> main: Initialize gstreamer object success.\n");

    /* Create gstreamer pipeline */
    ret = gst_create_pipeline(argc, argv, g_gstobj);
    if (ret) {
        printf("--> main: Create gstreamer pipeline failed.\n");
        status = -1;
        goto obj_release;
    }
    printf("--> main: Create gstreamer pipeline success.\n");

    /* Configuration gstreamer pipeline */
    ret = gst_config_pipeline(g_gstobj);
    if (ret < 0) {
        printf("--> main: Configuration gstreamer pipeline failed.\n");
        status = -1;
        goto release_pipeline;
    }
    printf("--> main: Configuration gstreamer pipeline success.\n");

    /* Play the pipeline */
    ret = gst_exec(g_gstobj, main_loop);
    if(ret < 0) {
        printf("--> main: play failed.\n");
        goto release_pipeline;
    }
    printf("--> main: Ready for playing.\n");

    /* Create loop, keep listen for pipeline event */
    g_main_loop_run(main_loop);

release_pipeline:
    /* Release gstreamer pipeline */
    gst_release_pipeline(g_gstobj);

obj_release:
    /* Release gst object */
    gst_obj_release(g_gstobj);

    /* Release all associated memory. */
    g_main_loop_unref(main_loop);

    return status;
}