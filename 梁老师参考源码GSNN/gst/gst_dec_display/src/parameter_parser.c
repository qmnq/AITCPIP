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

static const char short_opts [] = ":l:x:r:vh";
static const struct option long_opts [] = {
    { "location",  required_argument,      NULL, 'l' },
    { "h26x",       required_argument,      NULL, 'x' },
    { "framerate",    required_argument,      NULL, 'r' },
    { "version",    no_argument,            NULL, 'v' },
    { "help",       no_argument,            NULL, 0 },
    { 0, 0, 0, 0 }
};

static void usage(char *prog_name) {
    printf("Usage: %s [options]\n"
            "Options:\n"
            "   -l | --location     the file path \n"
            "   -x | --h26x         select h264 or h265 parse\n"
            "   -r | --framerate    playing framerate.\n"
            "   -v | --version      Version Info.\n"
            "   --help              Show this message.\n\n"
            "\n"
            "e.g. :\n"
            "       ./%s -l test.mp4 -x h264 -r 60 \n"
            "\n"
            , prog_name, prog_name);
}

/* Parsing input parameters */
bool parse_parameter(struct _Params *params, int argc, char **argv) {
    bool flag = false;
    int c = 0;
    while ((c = getopt_long(argc, argv, short_opts, long_opts, NULL))!= -1) {
        flag = true;

        switch (c) {
        case 'l':
            params->location=optarg;
            break;
        case 'v':
            printf("version : %s\n", VERSION);
            exit(0);
        case 'r':
            params->framerate = atoi(optarg);
            break;
        case 'x':
            params->h26x=optarg;
            break;
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
