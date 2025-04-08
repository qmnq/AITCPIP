/* Copyright 2019 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */

#ifndef PARAMETER_PARSER_H
#define PARAMETER_PARSER_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#if defined (__cplusplus)
extern "C" {
#endif

enum _Mode {
    M_SAVE,
    M_DISPLAY,
    M_UDP,
    M_DIS_SAVE,
    M_INVALID
};

struct _Params {
    enum _Mode mode;
    char *device;
    char *host;
    char *file;

    int  height;
    int  width;
    int  port;
};

bool parse_parameter(struct _Params *params, int argc, char **argv);

#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif /* PARAMETER_PARSER_H */
