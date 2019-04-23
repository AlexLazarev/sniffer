//
// Created by Alex on 2019-04-18.
//

#include "error.h"

void error(int key, char *info) {
    switch (key) {
        case ERROR_NOT_VALID_IP:
            fprintf(stderr, "Not valid IP: %s\n", info);
            break;
        case ERROR_NETMASK:
            fprintf(stderr, "Couldn't get netmask: %s\n", info);
            break;
        case ERROR_OPEN_DEVICE:
            fprintf(stderr, "Couldn't open device: %s\n", info);
            break;
        case ERROR_PARSE_FILTER:
            fprintf(stderr, "Couldn't parse filter: %s\n", info);
            break;
        case ERROR_INSTALL_FILTER:
            fprintf(stderr, "Couldn't install filter: %s\n", info);
            break;
        case ERROR_NOT_FOUND_DEFAULT_DEVICE:
            fprintf(stderr, "Couldn't find default device: %s\n", info);
        default:
            fprintf(stderr, "%s\n", info);
    }
    exit(2);
}