/* Copyright 2024 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */

#ifndef PARAMETER_PARSER_H
#define PARAMETER_PARSER_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#if defined (__cplusplus)
extern "C" {
#endif

struct _Params {

    int     numbuffer;
    int     framrate;
    int     pattern;
    char    *h26x;
    int     height;
    int     width;
    char    *file;
};

bool parse_parameter(struct _Params *params, int argc, char **argv);

#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif /* PARAMETER_PARSER_H */
