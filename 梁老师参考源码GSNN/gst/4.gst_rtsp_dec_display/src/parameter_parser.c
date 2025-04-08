/* Copyright 2023 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <libgen.h>

#include "parameter_parser.h"

const char * const VERSION = "1.0";

static const char short_opts [] = ":u:s:vh";
static const struct option long_opts [] = {
    { "url",        required_argument,    NULL, 'u' },
    { "show-fps",   required_argument,    NULL, 's' },
    { "version",    no_argument,          NULL, 'v' },
    { "help",       no_argument,          NULL, 'h' },
    { 0, 0, 0, 0 }
};

static void usage(char *prog_name) {
    printf ("Usage: %s [options]\n\n"
            "Options:\n"
            " -u | --url            RTSP url.\n"
            " -s | --show-fps       Whether to display the frame rate. (default value: 0)\n"
            " -v | --version        Version info.\n"
            " -h | --help           Show help message.\n\n"
            "e.g. :\n"
            "   ./%s -u rtsp://admin:tl123456@192.168.0.178:554/h264/ch1/main/av_stream -s 1\n",
            prog_name,
            prog_name);
}

/* Parsing input parameters */
bool parse_parameter(struct _Params *params, int argc, char **argv) {

    int c = 0;
    int show_fps = 0;
    
    /* Default value */
    params->show_fps = false;

    while ((c = getopt_long(argc, argv, short_opts, long_opts, NULL))!= -1) {
        switch (c) {
        case 'u':
            params->url = optarg;
            break;
        case 's':
            show_fps = strtoul(optarg, 0, 10);
            if(show_fps == 1) {
                params->show_fps = true;
            }
            break;
        case 'v':
            printf("version : %s\n", VERSION);
            exit(0);
        case 'h':
            usage(basename(argv[0]));
            exit(0);
        default :
            return false;
        }
    }
    
    /* Some parameters MUST specify. */
    if (params->url == NULL ) {
        return false;
    }
    return true;
}
