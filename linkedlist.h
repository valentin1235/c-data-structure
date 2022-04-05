#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "node.h"

typedef enum {
    FALSE = 0,
    TRUE = 1
} Bool;


Bool add_ordered(list_node_t** head, int value);
Bool add_at(list_node_t** head, size_t index, int value);
Bool remove_last(list_node_t** head);
Bool remove_at(list_node_t** head, size_t index);
void print_node(list_node_t** head);


#endif /* LINKEDLIST_H */
