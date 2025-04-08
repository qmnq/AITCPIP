 /* Copyright (C) 2013 Guangzhou Tronlong Electronic Technology Co., Ltd. - www.tronlong.com */

#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

#include "util.h"

static void usage(char *name) {
    printf("usage: %s [-Moisth]\n", name);
    printf("\t-M <drm-module>\tset DRM module\n");
    printf("\t-o <connector_id>:<crtc_id>:<mode>\tset a mode\n");
    printf("\t-i <video-node>\tset video node like /dev/video*\n");
    printf("\t-S <widthxheight>\tset input resolution\n");
    printf("\t-f <fourcc>\tset input format using 4cc\n");
    printf("\t-F <fourcc>\tset output format using 4cc\n");
    printf("\t-b buffer_count\tset number of buffers\n");
    printf("\t-h\tshow this help\n");
}

int parse_args(int argc, char *argv[], struct Setup *s) {
    if (argc <= 1)
        usage(argv[0]);

    int c, ret;
    memset(s, 0, sizeof(*s));

    while ((c = getopt(argc, argv, "M:o:i:S:f:F:b:h")) != -1) {
        switch (c) {
        case 'M':
            strncpy(s->module, optarg, 31);
            break;
        case 'o':
            ret = sscanf(optarg, "%u:%u:%31s", &s->conn_id, &s->crtc_id,
                s->modestr);
            if (WARN_ON(ret != 3, "incorrect mode description\n"))
                return -1;
            break;
        case 'i':
            strncpy(s->video, optarg, 31);
            break;
        case 'S':
            ret = sscanf(optarg, "%ux%u", &s->w, &s->h);
            if (WARN_ON(ret != 2, "incorrect input size\n"))
                return -1;
            break;
        case 'f':
            if (WARN_ON(strlen(optarg) != 4, "invalid fourcc\n"))
                return -1;
            s->in_fourcc = ((unsigned)optarg[0] << 0) |
                ((unsigned)optarg[1] << 8) |
                ((unsigned)optarg[2] << 16) |
                ((unsigned)optarg[3] << 24);
            break;
        case 'F':
            if (WARN_ON(strlen(optarg) != 4, "invalid fourcc\n"))
                return -1;
            s->out_fourcc = ((unsigned)optarg[0] << 0) |
                ((unsigned)optarg[1] << 8) |
                ((unsigned)optarg[2] << 16) |
                ((unsigned)optarg[3] << 24);
            break;
        case 'b':
            ret = sscanf(optarg, "%u", &s->buffer_count);
            if (WARN_ON(ret != 1, "incorrect buffer count\n"))
                return -1;
            break;
        case '?':
        case 'h':
            usage(argv[0]);
            exit(0);
        }
    }

    return 0;
}

void print_fps() {
    static int count = 0;
    static int first = 1;
    static struct timeval start;
    if (first) {
        gettimeofday(&start, NULL);
        first = 0;
    }

    struct timeval now;
    gettimeofday(&now, NULL);
    count++;
    int usec = (now.tv_sec - start.tv_sec) * 1000000 + (now.tv_usec - start.tv_usec);
    if (usec > 1000000) {
        printf("usec: %d, fps: %d\n", usec, count);
        start = now;
        count = 0;
    }
}
