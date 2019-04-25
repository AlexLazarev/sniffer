//
// Created by Alex on 2019-04-18.
//

#include "error.h"

void error(int key, char *info) {
    switch (key) {
        case ERROR_IP:
            fprintf(stderr, "Not valid IP");
            break;
        case ERROR_NETMASK:
            fprintf(stderr, "Couldn't get netmask");
            break;
        case ERROR_OPEN_DEVICE:
            fprintf(stderr, "Couldn't open device");
            break;
        case ERROR_PARSE_FILTER:
            fprintf(stderr, "Couldn't parse filter");
            break;
        case ERROR_INSTALL_FILTER:
            fprintf(stderr, "Couldn't install filter");
            break;
        case ERROR_NOT_FOUND_DEFAULT_DEVICE:
            fprintf(stderr, "Couldn't find default device");
        case ERROR_CREATE_THREAD:
            fprintf(stderr, "Couldn't create thread");
        case ERROR_JOIN_THREAD:
            fprintf(stderr, "Error joining thread");
        default:
            fprintf(stderr, "ERROR");
    }
    if (info) {
        fprintf(stderr, ": %s\n", info);
    } else {
        fprintf(stderr, "\n");
    }
    exit(EXIT_FAILURE);
}