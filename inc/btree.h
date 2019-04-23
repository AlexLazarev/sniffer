//
// Created by Alex on 2019-04-17.
//

#ifndef SNIFF_BTREE_H
#define SNIFF_BTREE_H

#include <stdint.h>
#include <stdlib.h>

typedef struct s_node t_node;

struct          s_node
{
    char        *key;
    uint32_t    count;
    t_node      *left;
    t_node      *right;
};

extern t_node *root;

void insert(char    *ip, t_node **node);
t_node *search(char *ip, t_node *node);
void preorder_print(t_node *node);

#endif //SNIFF_BTREE_H
