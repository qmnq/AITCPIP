#include <gst/gst.h>

//手动创建Pipeline和Element。
//命令行的话就是：gst_inspect-1.0 videotestsrc pattern=11 ! videoconvert ! autovideosink

int main(int argc,char *argv[])
{
//*********************************************************************
    //创建Pipeline容器、source、sink。他们都属于Element。
    //那么容器Pipeline就相当于链表的头指针。只要拿到头，整个链表都可以搞定。
    GstElement *pipeline,*source,*sink;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeRetuen ret;
//*********************************************************************
    //初始化GST
    gst_init(&argc,&argv);
//*********************************************************************
    //创建（最基本的）Element
    //参考第一章的命令来学习这一节：gst-launch-1.0 videotestsrc pattern=11 ! videoconvert ! autovideosink
    source = gst_element_factory_make("videotestsrc","source");//注意：videotestsrc和autovideosink名字不能乱写。
    sink = gst_element_factory_make("autovideosink","sink");
//*********************************************************************
    //创建空Pipeline:
    pipeline = gst_pipeline_new("test-pipeline");
    //判断pipeline、source、source是否创建成功，如果一个为空，就表示其创建失败。
    if( !pipeline || !source || !source)
    {
        g_printerr("Not all elements could be created.\n");
    }
//*********************************************************************
    //将空的pipeline 与 source、sink进行关联。
    //同时，有一个宏：GST_BIN,(由于一开始创建的pipeline、source、sink都属于Element指针，为了区分pipeline是容器还是source/sink是容器，便有了这个宏定义来告诉API谁是容器。他就会把source和sink传递到pipeline上面了。)
    gst_bin_add_many(GST_BIN(pipeline),source,sink,NULL);//此时就把source和sink关联到了pipeline上。但是source和sink的关联需要经过Pad。
//*********************************************************************
    if(gst_element_link(source,sink) != TRUE)   //所以source和sink的关联就是通过这里的gst_element_link(source,sink)来完成的，他就是用来连接（link）source和sink的
    {
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(pipeline);//关联失败，则释放pipeline.
        return -1;
    }
//*********************************************************************
    //修改某一个Element的属性，如：修改source的pattern属性（也就是设置成命令行命令： gst_inspect-1.0 videotestsrc  查到的参数）。
    g_object_set(source,"pattern",11,NULL);
//*********************************************************************
    //开始播放：
    ret = gst_element_set_state(pipeline,GST_STATE_PLAYING);
    if(ret == GST_STATE_CHANGE_FAILURE)
    {
        g_printerr("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(pipeline);
        return -1;
    }
//*********************************************************************
    //等到播放结束/发送错误，
    //拿到总线控制权
    bus = gst_element_get_bus(pipeline);
    //拿到bus后注册相关类型的消息。当结束/出错会返回消息。
    msg = gst_bus_timed_pop_filtered (bus,GST_CLOCK_TIME_NONE,GST_MESSAGE_ERROR | GST_MESSAGE_EOS); //三个参数：bus 状态 消息的类型（结束/出错）
//*********************************************************************
    //如果消息不为空，就解析消息,判断消息类型。
    if (msg != NULL)    //如果消息不为空，
    {
        GError *err;
        gchar *debug_info;
        switch(GST_MESSAGE_TYPE(msg))//GST_MESSAGE_TYPE判断消息类型。
        {
            case GST_MESSAGE_ERROR: //如果是Error，则打印错误消息。
                gst_message_parse_error(msg,&err,&debug_info);
                g_printerr("Error received from element %s:%s\n",GST_OBJECT_NAME(msg->src),err->message);
                g_printerr("Debugging information %s\n",debug_info ? debug_info : "none");
                g_clear_error(&err);
                g_free(debug_info);
            break;
            case GST_MESSAGE_EOS:
                g_print("End-Of-Stream reached.\n");
            break;
            default:
                //除了ERRORs和EOS之外的错误
                g_printerr("Unexpected message received.\n");
            break;
        }
        //释放消息。
        gst_message_unref (msg);
    }
//*********************************************************************
    //释放资源
    gst_object_unref(bus);  //释放bus
    gst_element_set_state(pipeline,GST_STATE_NULL); //把容器Pipline的状态设置为NULL ：Pipline state_null
    gst_object_unref (pipeline);    //最后释放Pipline
    return 0;

}
