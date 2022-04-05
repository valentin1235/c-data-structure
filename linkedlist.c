#include "linkedlist.h"

static int len(node_t** head)
{
    node_t** phead = head;
    int length = 0;

    while (*phead != NULL) {
        ++length;
        phead = &(*phead)->next;
    }

    return length;
}

Bool add_ordered(node_t** head, int value)
{
    node_t* new_node;
    node_t** phead = head;

    new_node = malloc(sizeof(node_t));
    new_node->value = value;

    if (*phead == NULL) {
        new_node->next = NULL;
        *phead = new_node;

        return TRUE;
    }

    while (*phead != NULL) {
        if ((*phead)->value > value) {
            break;
        }
        phead = &((*phead)->next);
    }

    new_node->next = *phead;
    *phead = new_node;

    return TRUE;
}

Bool add_at(node_t** head, size_t index, int value)
{
    node_t** phead = head;
    node_t* new_node;
    size_t i;

    if (index > len(head)) {
        return FALSE;
    }

    new_node = malloc(sizeof(node_t));
    new_node->value = value;

    for (i = 0; i < index; ++i) {
        phead = &(*phead)->next;
    }

    new_node->next = *phead;
    *phead = new_node;

    return TRUE;
}

Bool remove_last(node_t** head)
{
    node_t** phead = head;

    if (*phead == NULL) {
        return FALSE;
    }

    while ((*phead)->next != NULL) {
        phead = &((*phead)->next);
    }

    free(*phead);
    *phead = NULL;
}

Bool remove_at(node_t** head, size_t index)
{
    node_t** phead = head;
    size_t i;

    if (index > len(head)) {
        return FALSE;
    }

    for (i = 0; i < index; ++i) {
        phead = &(*phead)->next;
    }

    {
        node_t* next = (*phead)->next;
        free(*phead);
        *phead = next;
    }

    return TRUE;
}

void print_node(node_t** head)
{
    node_t** phead = head;

    printf("{ ");
    while (*phead != NULL) {
        printf("%d, ", (*phead)->value);
        phead = &(*phead)->next;
    }

    puts("}");

}
