//
// Created by Alex on 2019-04-18.
//

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include "command.h"
#define MAX 80
#define PORT 4455

static size_t get_index(int argc, char **argv) {
    for (size_t i = 0; i < SIZE(command); i++) {
            if (strcmp(command[i].name, argv[1]) == 0) {
                return i;
            }
    }
    return -1;
}
int main(int argc, char **argv) {
    int sock;
    int connection;
    struct sockaddr_in server;
    struct sockaddr_in cli;

    if (argc < 2) {
        usage();
        return EXIT_SUCCESS;
    }
    size_t index = get_index(argc, argv);
    if (index != -1) {
        if (index != START) {
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock < 0) {
                printf("socket creation failed...\n");
                exit(0);
            } else
                printf("Socket successfully created..\n");
            bzero(&server, sizeof(server));

            // assign IP, PORT
            server.sin_family = AF_INET;
            server.sin_addr.s_addr = inet_addr("127.0.0.1");
            server.sin_port = htons(PORT);
            if (connect(sock, (struct sockaddr *) &server, sizeof(server)) != 0) {
                printf("connection with the server failed...%s\n", strerror(errno));
                exit(0);
            } else
                printf("connected to the server..\n");
        }
        command[index].f(socket, argc, argv);
        // close the socket
        close(sock);
    } else {
        usage();
    }
    return EXIT_SUCCESS;
}
