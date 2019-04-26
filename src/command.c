//
// Created by Alex on 2019-04-18.
//

#include "command.h"
#include "error.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include "cli.h"

void start() {
    system("echo \"pXxfuAaR\n\" | sudo -S ./sniffer");
}

void stop(int sock) {
    write(sock, "stop", 4);
}

void show(int sock, int argc, char **argv) {
    struct in_addr addr;
    char *buf;

    printf("request ow..");
    if (argc == 4 && strcmp(argv[3], "count") == 0) {
        if (inet_aton(argv[2], &addr)) {
            printf("request show..");
            buf = inet_ntoa(addr);
            write(sock, "show", 4);
            write(sock, buf, strlen(buf));
            while (1) {
                read(sock, buf, MAX);
                if (strcmp(buf, "$end$") == 0){
                    break;
                }
                printf("%s", buf);
            }
        }
        else {
            error(ERROR_IP, argv[2]);
        }
    } else {
        usage();
    }
}

void select_iface(int sock, int argc, char **argv) {
    if (argc == 4 && strcmp(argv[2], "iface") == 0) {
        write(sock, argv[3], strlen(argv[3]));
    } else {
        usage();
    }
}

void stat(int sock, int argc, char **argv) {
    if (argc == 3) {
        write(sock, argv[2], strlen(argv[2]));
    } else if (argc == 2) {
        write(sock, "all", 3);
    }
    else {
        usage();
    }
}

void help() {
    usage();
}
