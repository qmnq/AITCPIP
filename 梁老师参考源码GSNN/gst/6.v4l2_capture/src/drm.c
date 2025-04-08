 /* Copyright (C) 2013 Guangzhou Tronlong Electronic Technology Co., Ltd. - www.tronlong.com */

#include <unistd.h>
#include <sys/ioctl.h>

#include "drm.h"
#include "util.h"

/* create NV12 buffer by DRM */
int drm_nv12_buffer_create(int drmfd, struct Buffer *b, struct Setup *s) {
    int ret;
    struct drm_mode_create_dumb gem;
    struct drm_mode_destroy_dumb gem_destroy;

    memset(&gem, 0, sizeof gem);
    gem.width = s->w;
    gem.height = s->h;
    gem.bpp = 16; // for NV12
    gem.size = s->size;
    ret = ioctl(drmfd, DRM_IOCTL_MODE_CREATE_DUMB, &gem);
    if (WARN_ON(ret, "CREATE_DUMB failed: %s\n", ERRSTR))
        return -1;
    printf("bo %u %ux%u bpp %u size %llu (%u)\n", gem.handle, gem.width, gem.height, gem.bpp, gem.size, s->size);
    b->bo_handle = gem.handle;

    struct drm_prime_handle prime;
    memset(&prime, 0, sizeof prime);
    prime.handle = b->bo_handle;
    ret = ioctl(drmfd, DRM_IOCTL_PRIME_HANDLE_TO_FD, &prime);
    if (WARN_ON(ret, "PRIME_HANDLE_TO_FD failed: %s\n", ERRSTR))
        goto fail_gem;
    b->fd = prime.fd;

    /* 0: Y, 1: UV, 2: Not Used 3: Not Used */
    uint32_t offsets[4];
    uint32_t pitches[4];
    uint32_t bo_handles[4];
    offsets[0] = 0;
    pitches[0] = s->pitch;
    bo_handles[0] = b->bo_handle;
    offsets[1] = s->w * s->h;
    pitches[1] = s->pitch;
    bo_handles[1] = b->bo_handle;

    unsigned int fourcc = s->out_fourcc;
    if (!fourcc)
        fourcc = s->in_fourcc;
    ret = drmModeAddFB2(drmfd, s->w, s->h, fourcc, bo_handles,
        pitches, offsets, &b->fb_handle, 0);
    if (WARN_ON(ret, "drmModeAddFB2 failed: %s\n", ERRSTR))
        goto fail_prime;

    return 0;

fail_prime:
    close(b->fd);

fail_gem:
    memset(&gem_destroy, 0, sizeof gem_destroy);
    gem_destroy.handle = b->bo_handle,
    ret = ioctl(drmfd, DRM_IOCTL_MODE_DESTROY_DUMB, &gem_destroy);
    WARN_ON(ret, "DESTROY_DUMB failed: %s\n", ERRSTR);

    return -1;
}

/* find target CRTC and Connector */
int drm_find_mode(int drmfd, drmModeModeInfo *m, struct Setup *s, uint32_t *con) {
    int ret = -1;
    int i;
    drmModeRes *res = drmModeGetResources(drmfd);
    if (WARN_ON(!res, "drmModeGetResources failed: %s\n", ERRSTR))
        return -1;

    if (WARN_ON(res->count_crtcs <= 0, "drm: no crts\n"))
        goto fail_res;

    s->crtc_idx = -1;

    for (i = 0; i < res->count_crtcs; ++i) {
        if (s->crtc_id == res->crtcs[i]) {
            s->crtc_idx = i;
            break;
        }
    }
    if (WARN_ON(s->crtc_idx == -1, "drm: CRTC %u not found\n", s->crtc_id))
        goto fail_res;
    if (WARN_ON(res->count_connectors <= 0, "drm: no connectors\n"))
        goto fail_res;

    drmModeConnector *c;
    c = drmModeGetConnector(drmfd, s->conn_id);
    if (WARN_ON(!c, "drmModeGetConnector failed: %s\n", ERRSTR))
        goto fail_res;
    if (WARN_ON(!c->count_modes, "connector supports no mode\n"))
        goto fail_conn;

    drmModeModeInfo *found = NULL;
    for (i = 0; i < c->count_modes; ++i)
        if (strcmp(c->modes[i].name, s->modestr) == 0)
            found = &c->modes[i];

    if (WARN_ON(!found, "mode %s not supported\n", s->modestr)) {
        fprintf(stderr, "Valid modes:");
        for (i = 0; i < c->count_modes; ++i)
            fprintf(stderr, " %s", c->modes[i].name);
        fprintf(stderr, "\n");
        goto fail_conn;
    }

    memcpy(m, found, sizeof(*found));
    if (con)
        *con = c->connector_id;
    ret = 0;

fail_conn:
    drmModeFreeConnector(c);

fail_res:
    drmModeFreeResources(res);

    return ret;
}

/* find plane which support overlay video */
int drm_find_plane(int drmfd, struct Setup *s) {
    drmModePlaneResPtr planes;
    drmModePlanePtr plane;
    unsigned int i;
    unsigned int j;
    int ret = 0;

    drmSetClientCap(drmfd, DRM_CLIENT_CAP_UNIVERSAL_PLANES, 1);
    planes = drmModeGetPlaneResources(drmfd);
    if (WARN_ON(!planes, "drmModeGetPlaneResources failed: %s\n", ERRSTR))
        return -1;

    for (i = 0; i < planes->count_planes; ++i) {
        plane = drmModeGetPlane(drmfd, planes->planes[i]);
        if (WARN_ON(!planes, "drmModeGetPlane failed: %s\n", ERRSTR))
            break;

        if (!(plane->possible_crtcs & (1 << s->crtc_idx))) {
            drmModeFreePlane(plane);
            continue;
        }

        for (j = 0; j < plane->count_formats; ++j) {
            if (plane->formats[j] == s->out_fourcc)
                break;
        }

        if (j == plane->count_formats) {
            drmModeFreePlane(plane);
            continue;
        }

        s->plane_id = plane->plane_id;
        drmModeFreePlane(plane);
        break;
    }

    if (i == planes->count_planes)
        ret = -1;

    drmModeFreePlaneResources(planes);
    return ret;
}
