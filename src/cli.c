//
// Created by Alex on 2019-04-18.
//

#include "command.h"

size_t get_index(int argc, char **argv) {
    for (size_t i = 0; i < SIZE(command); i++) {
            if (strcmp(command[i].name, argv[1]) == 0) {
                return i;
            }
    }
    return -1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        usage();
        return EXIT_SUCCESS;
    }
    size_t index = get_index(argc, argv);
    if (index != -1) {
        command[index].f(argc, argv);
    } else {
        usage();
    }
    return EXIT_SUCCESS;
}