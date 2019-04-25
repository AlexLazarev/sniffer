//
// Created by Alex on 2019-04-18.
//

#ifndef SNIFF_COMMAND_H
#define SNIFF_COMMAND_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

# define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

typedef struct  s_command {
    char *name;
    void (*f)();
}               t_command;

void    start(int socket);
void    stop(int socket);
void    show(int socket, int argc, char **argv);
void    select_iface(int socket, int argc, char **arv);
void    stat(int socket, int argc, char **arv);
void    help();
void    usage();
void    error(int error, char *info);

static t_command command[] = {
        {"start", start},
        {"stop", stop},
        {"show", show},
        {"select", select_iface},
        {"stat", stat},
        {"--help", help}
};

#endif //SNIFF_COMMAND_H
