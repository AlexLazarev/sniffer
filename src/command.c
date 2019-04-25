//
// Created by Alex on 2019-04-18.
//

#include "command.h"
#include "error.h"
#include <arpa/inet.h>

void start() {
    printf("start\n");
}

void stop() {
    printf("stop\n");
}

void show(int argc, char **argv) {
    struct in_addr addr;

    if (argc == 4 && strcmp(argv[3], "count") == 0) {
        if (inet_aton(argv[2], &addr)) {
            printf("show %s\n", inet_ntoa(addr));
        }
        else {
            error(ERROR_IP, argv[2]);
        }
    } else {
        usage();
    }
}

void select(int argc, char **argv) {
    if (argc == 4 && strcmp(argv[2], "iface") == 0) {
        printf("iface %s\n", argv[3]);
    } else {
        usage();
    }
}

void stat(int argc, char **argv) {
    if (argc == 3) {
        printf("stat %s\n", argv[2]);
    } else {
        usage();
    }
}

void help() {
    usage();
}
