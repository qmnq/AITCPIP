#include <gst/gst.h>

// Structure to contain all our information, so we can pass it to callbacks
// gcc hello-3.c -o hello-3 `pkg-config --cflags --libs gstreamer-1.0`
typedef struct CustomData {
    GstElement *pipeline;
    GstElement *source;
    GstElement *convert;
    GstElement *resample;
    GstElement *sink;
} CustomData;

static int g_padIndex = 0;
static void pad_added_handler(GstElement *src, GstPad *new_pad, CustomData *data);

int main(int argc, char *argv[]) {
    CustomData data;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;
    gboolean terminate = FALSE;

    // 初始化
    gst_init(&argc, &argv);

    // 创建element:
    /*
    uridecodebin 是一个元素，用于根据 URI 自动解码媒体流，比如音频或视频。

    首先，gst_element_factory_make函数的作用是根据元素工厂的名字创建一个元素实例。
    它的返回值类型是GstElement*，也就是指向 GstElement 结构体的指针。
    如果创建成功，返回指向新创建的 uridecodebin 元素的指针（GstElement*）；如果失败，比如元素工厂不存在或无法创建，返回 NULL。
    */
    data.source = gst_element_factory_make("uridecodebin", "source");        // 源
    data.convert = gst_element_factory_make("audioconvert", "convert");      // convert转换
    data.resample = gst_element_factory_make("audioresample", "resample");   // resample:音频重采样
    data.sink = gst_element_factory_make("autoaudiosink", "sink");           // sink：播放

    // 创建空Pipeline:
    data.pipeline = gst_pipeline_new("test-pipeline");
    if (!data.pipeline ||!data.source ||!data.convert ||!data.resample ||!data.sink) {
        g_printerr("Not all elements could be created.\n");
        return -1;
    }

    // 关联Element和Pipeline:
    gst_bin_add_many(GST_BIN(data.pipeline), data.source, data.convert, data.resample, data.sink, NULL);
    if (!gst_element_link_many(data.convert, data.resample, data.sink, NULL)) {
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(data.pipeline);
        return -1;
    }

    // 设置源的属性URI:
    g_object_set(data.source, "uri", "https://gstreamer.freedesktop.org/media/sintel_trailer-480p.webm", NULL);

    // 信号连接：
    g_signal_connect(data.source, "pad-added", G_CALLBACK(pad_added_handler), &data);	//pad_added_handler是信号的回调处理函数

    // 开始播放：
    ret = gst_element_set_state(data.pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        g_printerr("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(data.pipeline);
        return -1;
    }

    // bus总线接听信号：
    bus = gst_element_get_bus(data.pipeline);
    do {	//消息循环
        msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_STATE_CHANGED | GST_MESSAGE_ERROR | GST_MESSAGE_EOS); //接听消息，如果没有消息就阻塞在这里
        // 判断信号：
        if (msg != NULL) {
            GError *err;
            gchar *debug_info;
            switch (GST_MESSAGE_TYPE(msg)) {
                case GST_MESSAGE_ERROR:
                    gst_message_parse_error(msg, &err, &debug_info);
                    g_printerr("Error received from element %s:%s\n", GST_OBJECT_NAME(msg->src), err->message);
                    g_printerr("Debugging information %s\n", debug_info? debug_info : "none");
                    g_clear_error(&err);
                    g_free(debug_info);
                    terminate = TRUE;
                    break;
                case GST_MESSAGE_EOS:
                    g_print("End-Of-Stream reached.\n");
                    terminate = TRUE;
                    break;
                case GST_MESSAGE_STATE_CHANGED:
                    if (GST_MESSAGE_SRC(msg) == GST_OBJECT(data.pipeline)) {
                        GstState old_state, new_state, pending_state;
                        gst_message_parse_state_changed(msg, &old_state, &new_state, &pending_state);
                        g_print("Pipeline state changed from %s to %s:\n", gst_element_state_get_name(old_state), gst_element_state_get_name(new_state));
                    }
                    break;
                default:
                    g_printerr("Unexpected message received.\n");
                    break;
            }
            // 释放消息。
            gst_message_unref(msg);
        }
    } while (!terminate);

    // 释放资源
    gst_object_unref(bus);
    gst_element_set_state(data.pipeline, GST_STATE_NULL);
    gst_object_unref(data.pipeline);

    return 0;
}


// 函数的具体实现
//形参是Gstreamer运行时引擎传递给我们的，Gstreamer的运行时引擎在调用这个回调函数，所以new_pad参数是其传递给我们的。
static void pad_added_handler(GstElement *src, GstPad *new_pad, CustomData *data) {
    g_print("\n ========> pad_added_handler :%d.\n", g_padIndex++);
    // gst_element_get_static_pad获取静态pad，convert就是转换，sink表示去往哪里。
    GstPad *sink_pad = gst_element_get_static_pad(data->convert, "sink");
    GstPadLinkReturn ret;
    GstCaps *new_pad_caps = NULL;       // capabilities表示能力。
    GstStructure *new_pad_struct = NULL;
    const gchar *new_pad_type = NULL;

    g_print("Received new pad '%s' from '%s': \n", GST_PAD_NAME(new_pad), GST_ELEMENT_NAME(src));

    /* If our converter is already linked, we have nothing to do here */
    // 判断是否连接上了，如果是，则什么都不做，直接跳转到exit.
    if (gst_pad_is_linked(sink_pad)) {
        g_print("we are already linked. Ignoring.\n");
        goto exit;
    }

    /* Check the new pad's type */
    new_pad_caps = gst_pad_get_current_caps(new_pad);	//根据new_pad获得能力caps
    new_pad_struct = gst_caps_get_structure(new_pad_caps, 0); //再进一步根据能力caps得到struct
    new_pad_type = gst_structure_get_name(new_pad_struct);	//根据struct再获得name

    //这里只处理音频，不处理视频
    if (!g_str_has_prefix(new_pad_type, "audio/x-raw")) 	//使用g_str_has_prefix判断名字里面是否有前缀audio/x-raw，如果没有，就退出来什么都不管，如果有的话
    {
        g_print("It has type '%s' which is not raw audio. Ignoring.\n", new_pad_type);
        goto exit;
    }

    /* Attempt the link */
    // 如果没有连接，则尝试连接。
    ret = gst_pad_link(new_pad, sink_pad);	//gst_pad_link连接new_pad与sink_pad
    if (GST_PAD_LINK_FAILED(ret)) {
        g_print("Type is '%s' but link failed.\n", new_pad_type);
    } else {
        g_print("Link succeeded (type '%s').\n", new_pad_type);
    }

exit:
    /* Unreference the new pad's caps, if we got them */
    if (new_pad_caps != NULL)
        gst_caps_unref(new_pad_caps);
    /* Unreference the sink pad */
    gst_object_unref(sink_pad);
}
