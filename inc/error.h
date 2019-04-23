//
// Created by Alex on 2019-04-18.
//

#ifndef SNIFF_ERROR_H
#define SNIFF_ERROR_H

#include <stdio.h>
#include <stdlib.h>

enum e_error {
    ERROR_NOT_VALID_IP,
    ERROR_NETMASK,
    ERROR_OPEN_DEVICE,
    ERROR_PARSE_FILTER,
    ERROR_INSTALL_FILTER,
    ERROR_NOT_FOUND_DEFAULT_DEVICE
};

void error(int key, char *info);

#endif //SNIFF_ERROR_H
