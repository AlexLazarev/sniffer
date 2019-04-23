//
// Created by Alex on 2019-04-17.
//

#include <btree.h>
#include <string.h>
#include <stdio.h>

t_node          *root = NULL;

void insert(char    *key, t_node **node)
{
    if (node) {
        if (*node == NULL) {
            *node = (t_node *) malloc(sizeof(t_node));
            (*node)->key = strdup(key);
            (*node)->count = 1;
            (*node)->left = NULL;
            (*node)->right = NULL;
            return;
        }
        int cmp = strcmp(key, (*node)->key);
        if (cmp < 0) {
            insert(key, &(*node)->left);
        } else if (cmp > 0) {
            insert(key, &(*node)->right);
        } else {
            (*node)->count++;
        }
    }
}

t_node *search(char *key, t_node *node)
{
    int cmp;

    if (node) {
        cmp = strcmp(key, node->key);

        if (cmp == 0) {
            return node;
        }
        else if (cmp < 0) {
            return search(key, node->left);
        }
        else {
            return search(key, node->right);
        }
    }
    return NULL;
}

void preorder_print(t_node *node)
{
    if (node == NULL) {
        return;
    }
    printf("%s  : %d\n", node->key, node->count);
    preorder_print(node->left);
    preorder_print(node->right);
}