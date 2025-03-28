/* Copyright 2021 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */

#ifndef PARAMETER_PARSER_H
#define PARAMETER_PARSER_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#if defined (__cplusplus)
extern "C" {
#endif

struct _Params {
    char  *url;         /* rtsp url */
    int   fps;          /* capture framrate */
    int   width;        /* capture image width */
    int   height;       /* capture image height */
    bool  show_fps;     /* Whether to display the frame rate */
};

bool parse_parameter(struct _Params *params, int argc, char **argv);

#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif /* PARAMETER_PARSER_H */
