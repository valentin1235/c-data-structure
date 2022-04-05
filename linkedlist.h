#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef enum {
    FALSE = 0,
    TRUE = 1
} Bool;

typedef struct node {
    int value;
    struct node* next;
} node_t;


Bool add_ordered(node_t** head, int value);
Bool add_at(node_t** head, size_t index, int value);
Bool remove_last(node_t** head);
Bool remove_at(node_t** head, size_t index);
void print_node(node_t** head);


#endif /* LINKEDLIST_H */
