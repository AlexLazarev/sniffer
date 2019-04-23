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
/*
static size_t get_index(int argc, char **argv) {
    for (size_t i = 0; i < SIZE(command); i++) {
            if (strcmp(command[i].name, argv[1]) == 0) {
                return i;
            }
    }
    return -1;
}
int main(int argc, char **argv) {
    int             socket;
    struct sockaddr_in server;

    if (argc < 2) {
        usage();
        return EXIT_SUCCESS;
    }
    size_t index = get_index(argc, argv);
    if (index != -1) {

        socket = socket(PF_INET, SOCK_STREAM, 0);
        if (socket < 0) {
            perror("ERROR opening socket");
            exit(1);
        }
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(PORT);
        server.sin_addr.s_addr = inet_addr("127.0.0.1");

        connect(socket, (struct sockaddr*)&server, sizeof(server));
        recv(socket, "kek", 3, 0);

        command[index].f(argc, argv);
    } else {
        usage();
    }
    return EXIT_SUCCESS;
}*/

#define MAX 80
#define PORT 4455

void func(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, sizeof(buff));
        printf("Enter the string : ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n')
            ;
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    int sock;
    int connection;
    struct sockaddr_in server;
    struct sockaddr_in cli;

    // socket create and varification
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&server, sizeof(server));

    // assign IP, PORT
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) != 0) {
        printf("connection with the server failed...%s\n", strerror(errno));
        exit(0);
    }
    else
        printf("connected to the server..\n");

    // function for chat
    func(sock);

    // close the socket
    close(sock);
    return 0;
}