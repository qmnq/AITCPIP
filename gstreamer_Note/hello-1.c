#include <gst/gst.h>
//对照笔记的两张图来看代码。
int main (int argc, char *argv[])
{
    //常见的结构体 Pad Bus Message
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;
    //初始化gstreamer
    gst_init (&argc, &argv);
    //parse_launch函数返回的是GstElement类型的结构体指针：pipeline
    pipeline = gst_parse_launch("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",NULL);
    //开始播放：gst_element对应上面的pipline容器,set_state设置状态为：playing
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    //如果出错了就等待 或 流结束 EOS(end of stream)
    //此时拿到的是bus管理器，bus_manager
    bus = gst_element_get_bus(pipeline);
    //拿到bus后注册相关类型的消息。当结束/出错会返回消息。
    msg = gst_bus_timed_pop_filtered (bus,GST_CLOCK_TIME_NONE,GST_MESSAGE_ERROR | GST_MESSAGE_EOS); //三个参数：bus 状态 消息的类型（结束/出错）
    //当上面msg结束后，就释放资源。
    if (msg != NULL)    //如果消息不为空，
        gst_message_unref (msg);    //释放消息。
    gst_object_unref(bus);  //释放bus
    gst_element_set_state(pipeline,GST_STATE_NULL); //把容器Pipline的状态设置为NULL ：Pipline state_null
    gst_object_unref (pipeline);    //最后释放Pipline
    return 0;
}
