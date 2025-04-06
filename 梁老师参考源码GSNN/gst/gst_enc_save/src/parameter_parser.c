/* Copyright 2024 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */

#include "parameter_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <libgen.h>

const char * const VERSION = "0.1.0";

static const char short_opts [] = ":n:r:p:x:h:w:f:vh";
static const struct option long_opts [] = {
    { "numbuffer",  required_argument,      NULL, 'n' },
    { "framrate",   required_argument,      NULL, 'r' },
    { "pattern",    required_argument,      NULL, 'p' },
    { "h26x",       required_argument,      NULL, 'x' },
    { "height",     required_argument,      NULL, 'h' },
    { "width",      required_argument,      NULL, 'w' },
    { "file",       required_argument,      NULL, 'f' },
    { "version",    no_argument,            NULL, 'v' },
    { "help",       no_argument,            NULL, 0 },
    { 0, 0, 0, 0 }
};

static void usage(char *prog_name) {
    printf("Usage: %s [options]\n"
            "Options:\n"
            "   -n | --numbuffer    Completed video frame rate\n"
            "   -r | --framrate     Framrate\n"
            "   -p | --pattern      Select pattern\n"
            "   -x | --h26x         Select h264 or h265\n"
            "   -h | --height       The height of the resolution\n"
            "   -w | --width        The width of the resolution\n"
            "   -f | --file         Save as mp4 file\n"
            "   -v | --version      Version Info.\n"
            "   --help              Show this message.\n\n"
            "\n"
            "e.g. :\n"
            "       ./%s -n 600 -r 30 -p 0 -x h264 -w 1920 -h 1080 -f test.mp4\n"
            "\n"
            , prog_name, prog_name);
}

/* Parsing input parameters */
bool parse_parameter(struct _Params *params, int argc, char **argv) {
    bool flag = false;
    int c = 0;

    while ((c = getopt_long(argc, argv, short_opts, long_opts, NULL)) != -1) {
        flag = true;

        switch (c) {
        case 'n':
            params->numbuffer = atoi(optarg);
            break;
        case 'r':
            params->framrate = atoi(optarg);
            break;
        case 'p':
            params->pattern = atoi(optarg);
            break;
        case 'x':
            params->h26x = optarg;
            break;
        case 'h':
            params->height = atoi(optarg);
            break;
        case 'w':
            params->width = atoi(optarg);
            break;
        case 'f':
            params->file = optarg;
            break;
        case 'v':
            printf("version : %s\n", VERSION);
            exit(0);
        case 0: /* --help */
            usage(basename(argv[0]));
            exit(0);
        default :
            flag = false;
            break;
        }
    }

    if (flag == false) {
        printf("Try %s '--help' for more information\n", argv[0]);
        exit(-1);
    }

    return true;
}
