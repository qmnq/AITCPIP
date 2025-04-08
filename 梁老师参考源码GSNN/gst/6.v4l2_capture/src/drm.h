 /* Copyright (C) 2013 Guangzhou Tronlong Electronic Technology Co., Ltd. - www.tronlong.com */

#ifndef _DRM_H
#define _DRM_H

#include "util.h"

#include <libdrm/drm.h>
#include <libdrm/drm_mode.h>
#include <xf86drm.h>
#include <xf86drmMode.h>

struct Buffer {
    unsigned int bo_handle;
    unsigned int fb_handle;
    int fd;
};

int drm_nv12_buffer_create(int drmfd, struct Buffer *b, struct Setup *s);
int drm_find_mode(int drmfd, drmModeModeInfo *m, struct Setup *s, uint32_t *con);
int drm_find_plane(int drmfd, struct Setup *s);

#endif
