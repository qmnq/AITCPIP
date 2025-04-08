/* Copyright 2024 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */
//主流程：参数解析 → GStreamer初始化 → 启动管道 → 计时线程 → 信号处理 → 资源释放
//核心模块：
//├─ 结构体定义（GSTOBJ/GSTHANDLE/GSTELES）：分层管理管道、句柄、元素
//├─ 动态链接（on_pad_added）：处理demuxer的动态流pad
//├─ 管道构建（initialize_gst）：支持H264/H265双编码
//├─ 辅助功能：实时计时（timing_thread）、信号捕获（sig_handle）

#include <stdio.h>      //标准IO
#include <stdlib.h>     //内存管理
#include <stdbool.h>    //布尔类型
#include <unistd.h>     //系统调用
#include <gst/gst.h>    //gstreamer的核心库
#include "parameter_parser.h"   //自定义参数解析头文件

static struct _GSTOBJ *gstobj;      //全局GStreamer对象（贯穿整个流程）gstobj 作为整个管道的容器
static bool g_quit = false;         //退出标志（信号/线程共享）g_quit 用于多线程同步退出

struct _GSTHANDLE {     //句柄层：管理GStreamer核心对象
    GMainLoop *loop;         // 主事件循环（GStreamer运行核心）
    GstBus *bus;             // 消息总线（接收管道事件）
    GstElement *pipeline;    // 管道（所有元素的容器）
    GstMessage *msg;         // 临时消息存储
};

struct _GSTELES {           // 元素层：具体GStreamer组件: 定义完整的解码链（source→demuxer→parser→decoder→sink）
    GstElement *source,     // 文件源（filesrc）
               *demuxer,    // 解复用器（qtdemux）
               *parser,     // 码流解析器（h264parse/h265parse）
               *decoder,    // 解码器（mppvideodec）
               *sink,       // 输出设备（waylandsink）
               *capabilities,// 格式过滤器（capsfilter）
               *filter,         // 预留滤镜（未使用）
               *videoscale,     // 分辨率调整
               *videorate;      // 帧率调整
};

struct _GSTOBJ {            // 对象层：组合句柄和元素  分层结构体（句柄→元素→对象）
    struct _GSTHANDLE handle;
    struct _GSTELES elements;
};

//动态流链接回调
//qtdemux 解复用后动态获取视频流 pad，链接到 parser
//gst_pad_link实现元素间动态连接
//内存管理：必须调用g_free、gst_object_unref防止泄漏
static void on_pad_added(GstElement *element, GstPad *pad, gpointer data) {
    GstPad *sinkpad;
    GstElement *parser = (GstElement*)data; // 传入的parser元素
    GstCaps *caps;
    char *padname;

    padname = gst_pad_get_name(pad);        // 获取pad名称
    g_print("New pad '%s' detected.\n", padname);
    g_free(padname);                        // 必须释放gchar*

    caps = gst_pad_query_caps(pad, NULL);   // 查询pad的caps（媒体格式）
    if (!gst_caps_is_fixed(caps)) {          // 检查是否是固定格式（视频流特征）
        g_printerr("Pad caps are not fixed.\n");
        return;
    }
    /* Create an element to connect the src pad of the demuxer to the sink pad of the parser */
    sinkpad = gst_element_get_static_pad(parser, "sink");   // 获取parser的sink pad
    if (GST_PAD_IS_LINKED(sinkpad)) {                   // 防止重复链接
        g_printerr("Parser sink pad is already linked.\n");
        return;
    }
    if (gst_pad_link(pad, sinkpad) != GST_PAD_LINK_OK) {    // 动态链接pad
        g_printerr("Failed to link demuxer and parser.\n");
    }
    gst_object_unref(sinkpad);              // 释放pad引用
    gst_caps_unref(caps);                   // 释放caps引用
}

//响应 Ctrl+C（SIGINT），停止播放
//if里面直接操作全局 gstobj，需注意线程安全（此处主线程调用，安全）
static void sig_handle(int signal) {
    printf("\n\n\r\033[k");         // 清屏操作
    if (gstobj != NULL)
    {
         g_main_loop_quit(gstobj->handle.loop); // 终止主循环
    }
    g_quit = true;      // 设置退出标志
    sleep(1);           // 等待资源释放
}

/* Initialization of gstreamer */
//gst_init初始化 GStreamer 库
//107-114 行创建标准元素链（filesrc→qtdemux→解码器→输出）
//通过 caps 固定输出格式（NV12）和帧率
//通过信号连接实现动态流处理（qtdemux 的 pad-added 事件）
bool initialize_gst(int argc, char **argv, struct _GSTHANDLE *handle,struct _GSTELES *elements,struct _Params *params) {
    if (handle == NULL)
        return false;
    GstCaps *caps;
    gst_init(&argc, &argv);     // GStreamer初始化（必须第一个调用）
    handle->loop = g_main_loop_new(NULL, FALSE);    // 创建主循环

    /* Create a new pipeline */
    handle->pipeline = gst_pipeline_new("_pipeline");
    if (!handle->pipeline)
        return false;

    /* Creating Elements */
    handle->pipeline = gst_pipeline_new("mp4-player");  // 创建命名管道
    // 元素创建（H264分支）
    elements->source = gst_element_factory_make("filesrc", "file-source");
    elements->demuxer = gst_element_factory_make("qtdemux", "demuxer");
    elements->decoder = gst_element_factory_make("mppvideodec", "video-decoder");
    elements->sink = gst_element_factory_make("waylandsink", "video-sink");
    // ...（其他元素创建）
    elements->videorate = gst_element_factory_make("videorate", "videorate");
    elements->capabilities = gst_element_factory_make("capsfilter", "capsfilter");
    elements->videoscale = gst_element_factory_make("videoscale", "videoscale");

    if(strcmp(params->h26x,"h264") ==0 )    // 根据参数选择parser
    {
        elements->parser = gst_element_factory_make("h264parse", "h264parse");
        /*Check if the element was successfully created*/
        // 元素创建检查（缺失任意元素则失败）
        if( !elements->source || !elements->demuxer || !elements->decoder || !elements->sink ||
            !elements->parser || !elements->videorate ||  !elements->capabilities )
        {
            g_printerr("Failed to create elements. Exiting.\n");
            return false;
        }

        /*Set the frame rate for playback*/
        // 设置输出格式为NV12，固定帧率
        caps = gst_caps_new_simple("video/x-raw",
                                "format", G_TYPE_STRING, "NV12",
                                "framerate", GST_TYPE_FRACTION, params->framerate, 1,
                                NULL);
    }
    else if(strcmp(params->h26x,"h265") ==0)    /* H265分支，逻辑相同 */
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


    g_object_set(G_OBJECT(elements->capabilities), "caps", caps, NULL); // 应用caps
    gst_caps_unref(caps);

    /* Set filesrc Path */
    g_object_set(G_OBJECT(elements->source), "location", params->location, NULL);   // 设置文件路径

    /* Add elements to pipeline*/
    // 将元素添加到管道（顺序不影响，动态链接）
    gst_bin_add_many(GST_BIN(handle->pipeline), elements->source, elements->demuxer,
                        elements->parser, elements->decoder  ,  elements->videorate , 
                        elements->videoscale, elements->capabilities , elements->sink ,
                        NULL);

    /* link elements to pipeline*/
    // 静态链接（非动态部分）
    if((  gst_element_link(elements->source, elements->demuxer) &&
            gst_element_link(elements->parser, elements->decoder)&&
            gst_element_link(elements->decoder, elements->videorate)&&
            gst_element_link(elements->videorate, elements->videoscale)&&
            gst_element_link(elements->videoscale, elements->capabilities)&&
            gst_element_link(elements->capabilities, elements->sink)) != TRUE)
        {
            // 链接source→demuxer，decoder→videorate等固定链路
            g_printerr("Failed to link elements. Exiting.\n");
            return false;
        }

    /* Set the callback function for the "demuxer" to receive stream data */
    // 核心设计：通过pad-added信号动态链接demuxer与parser// 注册动态链接回调（核心设计）
    g_signal_connect(elements->demuxer, "pad-added", G_CALLBACK(on_pad_added), elements->parser);
    
    return true;
}

/* This thread is used to calculate the time spent */
//计时线程
//使用gettimeofday（精度微秒，此处取秒级）
//fflush必不可少（标准输出默认行缓冲，无换行时不刷新）
//\r\033[k是 ANSI 转义码（回车 + 清除行）
static void *timing_thread(void *arg) {
    static struct timeval t_start, t_current;
    int duration = 0;
    int hour = 0, min = 0, sec = 0;

    /* get start timestamp */
    gettimeofday(&t_start, NULL);    // ★获取启动时间
    printf(" starting \n\n");

    while (!g_quit) {
        /* get the current time */
        gettimeofday(&t_current, NULL);// 获取当前时间
        
        /* calculate thread duration time */
        duration = (t_current.tv_sec - t_start.tv_sec); // 计算秒差
        // 时分秒转换
        hour     = duration / 3600;
        min      = duration / 60 - (hour * 60);
        sec      = duration % 60;

        printf("-- Duration %02d:%02d:%02d --", hour, min, sec);

        /* Clear the read-write buffer */
        fflush(stdout);                      // ★强制刷新缓冲区（否则可能不显示
        /* Clear content from cursor to end of line */
        printf("\r\033[k");  // ★清行操作（光标回到行首并清空）
        sleep(1);       // 每秒更新一次
    }
    
    printf("Stoping\n");
    return (void *)0;
}

//总线消息处理
//作用：监听管道总线，处理结束（EOS）和错误（ERROR）事件
//注意：gst_message_parse_error解析错误信息后需手动释放error和debug（此处若debug未释放，存在泄漏）
static gboolean bus_call(GstBus *bus, GstMessage *msg,gpointer data) {
    GMainLoop *loop = (GMainLoop *)data;
    gchar  *debug;
    GError *error;

    switch (GST_MESSAGE_TYPE(msg)) {
    case GST_MESSAGE_EOS:       // 流结束
        g_print("End of stream\n");
        g_main_loop_quit(loop);  // 退出主循环
        break;

    case GST_MESSAGE_ERROR:     // 错误事件
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

//播放控制函数
//状态转换：GST_STATE_PLAYING启动管道
//线程管理：计时线程在管道启动后创建（异步执行）
bool play_gst_pipeline(struct _GSTHANDLE *handle) {
    pthread_t id;
    gboolean ret;

    if (handle == NULL)
        return false;

    /* Get pipeline message bus and monitoring messages */
    handle->bus = gst_pipeline_get_bus(GST_PIPELINE(handle->pipeline));
    gst_bus_add_watch(handle->bus, bus_call, handle->loop); // ★注册总线回调
    gst_object_unref(handle->bus);           // 释放临时引用

    /* Start the pipeline */
    ret = gst_element_set_state(handle->pipeline, GST_STATE_PLAYING);

    if (ret == GST_STATE_CHANGE_ASYNC || ret == GST_STATE_CHANGE_SUCCESS) {
        /* Crete timing thread */
        // 创建计时线程
        if (pthread_create(&id, NULL, timing_thread, NULL)) {
            printf("Creating timing thread failed !\n");
            return false;
        }
        pthread_detach(id); // 线程分离（自动回收资源）
    }

    g_main_loop_run(handle->loop);  // ★进入GStreamer主循环

    return true;
}

//资源释放
//标准流程：状态设为 NULL → 释放对象 → 释放循环
//注意：未释放 elements 中的各个元素（GStreamer 会自动释放，其属于管道子对象）
void release_gst(struct _GSTHANDLE *handle) {
    /* clean up */
    gst_element_set_state(handle->pipeline, GST_STATE_NULL);    // ★重置管道状态

    /* Release gst pipeline*/
    gst_object_unref(GST_OBJECT(handle->pipeline)); // 释放管道

    /* Quit loop */
    g_main_loop_unref(handle->loop);     // 释放主循环
}

//主函数
//流程控制：参数解析→初始化→播放→错误处理（goto 统一释放）
//内存管理：手动释放 gstobj（GStreamer 对象已在 release_gst 中释放）
int main(int argc, char *argv[]) {

    gboolean ret; 
    struct _Params params;
    bool pret;

    signal(SIGINT, sig_handle);     // 注册信号处理

    gstobj = (struct _GSTOBJ *)malloc(sizeof(struct _GSTOBJ));  // 分配全局对象
    memset(gstobj, 0, sizeof(struct _GSTOBJ));
    memset(&params, 0, sizeof(params));

    pret = parse_parameter(&params, argc, argv);// 解析命令行参数
    if(! pret)
        return -1;

    /*Initialization Gst*/
    // 初始化管道
    ret = initialize_gst(argc, argv, &gstobj->handle,&gstobj->elements,&params);
    if(! ret)
    {
        printf("\n Initialization Gst fail \n");
        goto err_release;
    }

    /* Play the pipeline */
    // 启动播放
    ret = play_gst_pipeline(&gstobj->handle);
    if (! ret) {
        printf(" \n Play the pipeline failed \n");
        goto err_release;
    }

err_release:
    /* Release gst pipeline*/
    release_gst(&gstobj->handle);// 释放资源
    free(gstobj);
    if (! ret)
        return -1;
    printf("Exit\n");
    return 0;
}

