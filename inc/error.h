//
// Created by Alex on 2019-04-18.
//

#ifndef SNIFF_ERROR_H
#define SNIFF_ERROR_H

#include <stdio.h>
#include <stdlib.h>

enum e_error {
    ERROR_IP,
    ERROR_NETMASK,
    ERROR_OPEN_DEVICE,
    ERROR_PARSE_FILTER,
    ERROR_INSTALL_FILTER,
    ERROR_NOT_FOUND_DEFAULT_DEVICE,
    ERROR_CREATE_THREAD,
    ERROR_JOIN_THREAD
};

void error(int key, char *info);

#endif //SNIFF_ERROR_H
