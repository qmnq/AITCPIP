 /* Copyright (C) 2013 Guangzhou Tronlong Electronic Technology Co., Ltd. - www.tronlong.com */

#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

#define ERRSTR strerror(errno)

#define BYE_ON(cond, ...) \
do { \
    if (cond) { \
        int errsv = errno; \
        fprintf(stderr, "ERROR(%s:%d) : ", \
            __FILE__, __LINE__); \
        errno = errsv; \
        fprintf(stderr,  __VA_ARGS__); \
        abort(); \
    } \
} while(0)

static inline int warn(const char *file, int line, const char *fmt, ...) {
    int errsv = errno;
    va_list va;
    va_start(va, fmt);
    fprintf(stderr, "WARN(%s:%d): ", file, line);
    vfprintf(stderr, fmt, va);
    va_end(va);
    errno = errsv;
    return 1;
}
#define WARN_ON(cond, ...) \
    ((cond) ? warn(__FILE__, __LINE__, __VA_ARGS__) : 0)

struct Setup {
    char module[32];
    int conn_id;
    uint32_t crtc_id;
    int crtc_idx;
    uint32_t plane_id;
    char modestr[32];
    char video[32];
    uint32_t w, h;
    uint32_t in_fourcc;
    uint32_t out_fourcc;
    uint32_t buffer_count;
    uint32_t size;
    uint32_t pitch;
};

int parse_args(int argc, char *argv[], struct Setup *s);
void print_fps();

#endif
