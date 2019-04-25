//
// Created by Alex on 2019-04-18.
//

#include "command.h"
#include "error.h"
#include <arpa/inet.h>
#include <unistd.h>

void start() {
    system("echo \"pXxfuAaR\n\" | sudo -S ./sniffer");
}

void stop(int socket) {
    write(socket, "stop", 4);
}

void show(int socket, int argc, char **argv) {
    struct in_addr addr;
    char *buf;

    if (argc == 4 && strcmp(argv[3], "count") == 0) {
        if (inet_aton(argv[2], &addr)) {
            buf = inet_ntoa(addr);
            write(socket, buf, strlen(buf));
        }
        else {
            error(ERROR_IP, argv[2]);
        }
    } else {
        usage();
    }
}

void select_iface(int socket, int argc, char **argv) {
    if (argc == 4 && strcmp(argv[2], "iface") == 0) {
        write(socket, argv[3], strlen(argv[3]));
    } else {
        usage();
    }
}

void stat(int socket, int argc, char **argv) {
    if (argc == 3) {
        write(socket, argv[2], strlen(argv[2]));
    } else if (argc == 2) {
        write(socket, "all", 3);
    }
    else {
        usage();
    }
}

void help() {
    usage();
}
