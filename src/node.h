#ifndef NODE_H
#define NODE_H

typedef struct list_node {
    int value;
    struct list_node* next;
} list_node_t;

typedef struct node {
    char* key;
    int value;
    struct node* next;
} node_t;

#endif /* NODE_H */
