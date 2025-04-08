/**
 * Copyright (C) 2013 Guangzhou Tronlong Electronic Technology Co., Ltd. - www.tronlong.com
 *
 * @file main.c
 *
 * @brief Example application main file.
 * This application display image from camera use v4l2 and drm
 *
 * @author Tronlong <support@tronlong.com>
 *
 * @version V1.0
 *
 * @date 2023-8-14
 **/

#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <poll.h>
#include <linux/videodev2.h>

#include "util.h"
#include "drm.h"

#define V4l2_PLANE_NUM 1

struct Setup s;

/* ctrl + c */
volatile bool g_quit = false;
static void sigint_handler(int signo) {
    (void)signo;
    g_quit = true;
}

static void v4l2_check_capability(int fd) {
    struct v4l2_capability caps;
    memset(&caps, 0, sizeof caps);
    int ret = ioctl(fd, VIDIOC_QUERYCAP, &caps);
    BYE_ON(ret, "VIDIOC_QUERYCAP failed: %s\n", ERRSTR);
    BYE_ON(~caps.capabilities & V4L2_CAP_VIDEO_CAPTURE_MPLANE,
        "video: multiplanar capture is not supported\n");
}

static void v4l2_set_format(int fd) {
    struct v4l2_format fmt;
    memset(&fmt, 0, sizeof fmt);
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;

    int ret = ioctl(fd, VIDIOC_G_FMT, &fmt);
    BYE_ON(ret < 0, "VIDIOC_G_FMT failed: %s\n", ERRSTR);
    printf("old format: width = %u, height = %u, 4cc = %.4s\n",
        fmt.fmt.pix.width, fmt.fmt.pix.height,
        (char*)&fmt.fmt.pix.pixelformat);

    fmt.fmt.pix.width = s.w;
    fmt.fmt.pix.height = s.h;
    if (s.in_fourcc)
        fmt.fmt.pix.pixelformat = s.in_fourcc;

    ret = ioctl(fd, VIDIOC_S_FMT, &fmt);
    BYE_ON(ret < 0, "VIDIOC_S_FMT failed: %s\n", ERRSTR);

    ret = ioctl(fd, VIDIOC_G_FMT, &fmt);
    BYE_ON(ret < 0, "VIDIOC_G_FMT failed: %s\n", ERRSTR);
    printf("cur format: width = %u, height = %u, 4cc = %.4s\n",
        fmt.fmt.pix.width, fmt.fmt.pix.height,
        (char*)&fmt.fmt.pix.pixelformat);

    s.in_fourcc = fmt.fmt.pix.pixelformat;
    s.w = fmt.fmt.pix.width;
    s.h = fmt.fmt.pix.height;
    s.size = fmt.fmt.pix.sizeimage;
    s.pitch = fmt.fmt.pix.width; /* for NV12 format image */
}

static void v4l2_request_buffers(int fd) {
    struct v4l2_requestbuffers rqbufs;
    memset(&rqbufs, 0, sizeof(rqbufs));
    rqbufs.count = s.buffer_count;
    rqbufs.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
    rqbufs.memory = V4L2_MEMORY_DMABUF;
    int ret = ioctl(fd, VIDIOC_REQBUFS, &rqbufs);
    BYE_ON(ret < 0, "VIDIOC_REQBUFS failed: %s\n", ERRSTR);
    BYE_ON(rqbufs.count < s.buffer_count, "video node allocated only "
        "%u of %u buffers\n", rqbufs.count, s.buffer_count);
}

static void v4l2_query_buffers(int fd, uint32_t buffer_count) {
    for (unsigned int i = 0; i < buffer_count; ++i) {
        struct v4l2_plane planes[V4l2_PLANE_NUM];
        memset(&planes, 0, sizeof(planes) * V4l2_PLANE_NUM);

        struct v4l2_buffer buf;
        memset(&buf, 0, sizeof(buf));
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
        buf.memory = V4L2_MEMORY_DMABUF;
        buf.index = i;
        buf.m.planes = planes;
        buf.length = V4l2_PLANE_NUM;
        int ret = ioctl(fd, VIDIOC_QUERYBUF, &buf);
        BYE_ON(ret < 0, "VIDIOC_QBUF for buffer %d failed: %s\n", buf.index, ERRSTR);
    }
}

int main(int argc, char *argv[]) {
    signal(SIGINT, sigint_handler);

    /* get command line arguments */
    int ret;
    ret = parse_args(argc, argv, &s);
    BYE_ON(ret, "failed to parse arguments\n");
    BYE_ON(s.module[0] == 0, "DRM module is missing\n");
    BYE_ON(s.video[0] == 0, "video node is missing\n");

    /* open drm device */
    int drmfd = drmOpen(s.module, NULL);
    BYE_ON(drmfd < 0, "drmOpen(%s) failed: %s\n", s.module, ERRSTR);

    /* find drm mode to display */
    uint32_t conn;
    drmModeModeInfo drmmode;
    ret = drm_find_mode(drmfd, &drmmode, &s, &conn);
    BYE_ON(ret, "failed to find valid mode\n");

    /* find drm plane to overlay NV12 video */
    ret = drm_find_plane(drmfd, &s);
    BYE_ON(ret, "failed to find compatible plane\n");

    /* open camera device */
    int v4lfd = open(s.video, O_RDWR);
    BYE_ON(v4lfd < 0, "failed to open %s: %s\n", s.video, ERRSTR);

    /* device must support multiplane capture */
    v4l2_check_capability(v4lfd);

    /* set camera format */
    v4l2_set_format(v4lfd);

    /* request v4l2 buffers */
    v4l2_request_buffers(v4lfd);

    /* query v4l2 buffers */
    v4l2_query_buffers(v4lfd, s.buffer_count);

    /* alloc drm buffers */
    struct Buffer buffer[s.buffer_count];
    for (unsigned int i = 0; i < s.buffer_count; ++i) {
        ret = drm_nv12_buffer_create(drmfd, &buffer[i], &s);
        BYE_ON(ret, "failed to create buffer%d\n", i);
    }
    /* bind v4l2 buffers with drm buffers and queue all into v4l2 driver to fill image */
    for (unsigned int i = 0; i < s.buffer_count; ++i) {
        struct v4l2_plane planes[V4l2_PLANE_NUM];
        memset(&planes, 0, sizeof(planes) * V4l2_PLANE_NUM);

        struct v4l2_buffer buf;
        memset(&buf, 0, sizeof buf);
        buf.index = i;
        buf.length = V4l2_PLANE_NUM;            
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
        buf.memory = V4L2_MEMORY_DMABUF;
        buf.m.planes = planes;
        buf.m.planes->m.fd = buffer[i].fd;
        ret = ioctl(v4lfd, VIDIOC_QBUF, &buf);
        BYE_ON(ret < 0, "VIDIOC_QBUF for buffer %d failed: %s (fd %u)\n",
            buf.index, ERRSTR, buffer[i].fd);
    }

    /* start capture */
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
    ret = ioctl(v4lfd, VIDIOC_STREAMON, &type);
    BYE_ON(ret < 0, "STREAMON failed: %s\n", ERRSTR);

    /* capture and display loop, break by ctrl + c */
    while (! g_quit) {
        /* wait frame */
        struct pollfd fds[] = { { .fd = v4lfd, .events = POLLIN } };
        ret = poll(fds, 2, 3000);
        if (ret <= 0)
            break;

        /* dequeue buffer */
        struct v4l2_plane planes[V4l2_PLANE_NUM];
        memset(&planes, 0, sizeof(planes) * V4l2_PLANE_NUM);
        struct v4l2_buffer buf;
        memset(&buf, 0, sizeof buf);
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
        buf.memory = V4L2_MEMORY_DMABUF;
        buf.m.planes = planes;
        buf.length = V4l2_PLANE_NUM;
        ret = ioctl(v4lfd, VIDIOC_DQBUF, &buf);
        BYE_ON(ret, "VIDIOC_DQBUF failed: %s\n", ERRSTR);

        /* display buffer */
        struct drm_mode_map_dumb arg;
        memset(&arg, 0, sizeof(arg));
        arg.handle = buffer[buf.index].bo_handle;
        ret = drmModeSetPlane(drmfd, s.plane_id, s.crtc_id,
                      buffer[buf.index].fb_handle, 0,
                      0, 0, s.w, s.h,
                      0, 0, s.w << 16, s.h << 16);
        BYE_ON(ret, "drmModeSetPlane failed: %s\n", ERRSTR);

        /* queue buffer */
        int cur = buf.index;
        memset(&planes, 0, sizeof(planes) * V4l2_PLANE_NUM);
        memset(&buf, 0, sizeof buf);
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
        buf.memory = V4L2_MEMORY_DMABUF;
        buf.index = cur;
        buf.length = V4l2_PLANE_NUM;            
        buf.m.planes = planes;
        buf.m.planes->m.fd = buffer[cur].fd;

        ret = ioctl(v4lfd, VIDIOC_QBUF, &buf);
        BYE_ON(ret, "VIDIOC_QBUF(index = %d) failed: %s\n", cur, ERRSTR);

        /* show frame rate */
        print_fps();
    }

    /* stop capture */
    ret = ioctl(v4lfd, VIDIOC_STREAMOFF, &type);
    BYE_ON(ret < 0, "STREAMOFF failed: %s\n", ERRSTR);

    /* release */
    close(v4lfd);
    close(drmfd);

    printf("exit.\n");

    return 0;
}
