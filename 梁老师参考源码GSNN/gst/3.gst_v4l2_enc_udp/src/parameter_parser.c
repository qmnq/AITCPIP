/* Copyright 2019 Tronlong Elec. Tech. Co. Ltd. All Rights Reserved. */

#include "parameter_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <libgen.h>

const char * const VERSION = "0.1.0";

static const char short_opts [] = ":m:d:h:w:a:f:vh";
static const struct option long_opts [] = {
    { "mode",       required_argument,      NULL, 'm' },
    { "device",     required_argument,      NULL, 'd' },
    { "height",     required_argument,      NULL, 'h' },
    { "width",      required_argument,      NULL, 'w' },
    { "address",    required_argument,      NULL, 'a' },
    { "file",       required_argument,      NULL, 'f' },
    { "version",    no_argument,            NULL, 'v' },
    { "help",       no_argument,            NULL, 0 },
    { 0, 0, 0, 0 }
};

static void usage(char *prog_name) {
    printf("Usage: %s [options]\n"
            "Options:\n"
            "   -m | --mode         Mode selection [display] [save] [udp] [dis-save]\n"
            "   -d | --device       Input device node\n"
            "   -h | --height       The height of the input and output resolution\n"
            "   -w | --width        The width of the input and output resolution\n"
            "   -a | --address      Host address in mode [udp] -- host:port\n"
            "   -f | --file         Filename in mode [save] [dis-save], save as h264 file\n"
            "   -v | --version      Version Info.\n"
            "   --help              Show this message.\n\n"
            "\n"
            "e.g. :\n"
            "       ./%s -m display -d /dev/video1 -w 1920 -h 1080\n"
            "       ./%s -m save -d /dev/video1 -w 1920 -h 1080 -f test.264\n"
            "       ./%s -m udp -d /dev/video1 -w 1920 -h 1080 -a 192.168.11.36:8080\n"
            "       ./%s -m dis-save -d /dev/video1 -w 1920 -h 1080 -f test.264\n"
            "\n"
            , prog_name, prog_name, prog_name, prog_name, prog_name);
}

static int split(char **dst, char *src, const char *sep, int count) {
    if (src == NULL || strlen(src) == 0)
        return 0;

    if (sep == NULL || strlen(sep) == 0)
        return 0;

    if (count < 2)
        return 0;

    int cnt = 0;

    char *ptr = NULL;
    ptr = strsep(&src, sep);
    while(ptr != NULL) {
        *dst++ = ptr;

        if (++cnt == count)
            break;

        ptr = strsep(&src, sep);
    }

    return cnt;
}

enum _Mode mode_select(char *mode) {
    if (mode == NULL)
        return M_INVALID;

    if (strcmp(mode, "save") == 0)
        return M_SAVE;

    else if (strcmp(mode, "display") == 0)
        return M_DISPLAY;

    else if (strcmp(mode, "udp") == 0)
        return M_UDP;

    else if (strcmp(mode, "dis-save") == 0)
        return M_DIS_SAVE;

    else
        return M_INVALID;
}

/* Parsing input parameters */
bool parse_parameter(struct _Params *params, int argc, char **argv) {
    bool flag = false;
    int c = 0;
    char *buf[2] = {0};

    while ((c = getopt_long(argc, argv, short_opts, long_opts, NULL))!= -1) {
        flag = true;

        switch (c) {
        case 'm':
            params->mode = mode_select(optarg);
            if(params->mode == M_INVALID)
                flag = false;
            break;
        case 'd':
            params->device = optarg;
            break;
        case 'h':
            params->height = atoi(optarg);
            break;
        case 'w':
            params->width = atoi(optarg);
            break;
        case 'a':
            if (split(buf, optarg, ":", 2) == 2) {
                params->host = buf[0];
                params->port = atoi(buf[1]);
            } else {
                flag = false;
            }
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
