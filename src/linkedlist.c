#include "linkedlist.h"

static size_t len(list_node_t** head)
{
    list_node_t** phead = head;
    size_t length = 0;

    while (*phead != NULL) {
        ++length;
        phead = &(*phead)->next;
    }

    return length;
}

Bool add_ordered(list_node_t** head, int value)
{
    list_node_t* new_node;
    list_node_t** phead = head;

    new_node = malloc(sizeof(list_node_t));
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

Bool add_at(list_node_t** head, size_t index, int value)
{
    list_node_t** phead = head;
    list_node_t* new_node;
    size_t i;

    if (index > len(head)) {
        return FALSE;
    }

    new_node = malloc(sizeof(list_node_t));
    new_node->value = value;

    for (i = 0; i < index; ++i) {
        phead = &(*phead)->next;
    }

    new_node->next = *phead;
    *phead = new_node;

    return TRUE;
}

Bool remove_last(list_node_t** head)
{
    list_node_t** phead = head;

    if (*phead == NULL) {
        return FALSE;
    }

    while ((*phead)->next != NULL) {
        phead = &((*phead)->next);
    }

    free(*phead);
    *phead = NULL;

    return TRUE;
}

Bool remove_at(list_node_t** head, size_t index)
{
    list_node_t** phead = head;
    size_t i;

    if (index > len(head)) {
        return FALSE;
    }

    for (i = 0; i < index; ++i) {
        phead = &(*phead)->next;
    }

    {
        list_node_t* next = (*phead)->next;
        free(*phead);
        *phead = next;
    }

    return TRUE;
}

void print_node(list_node_t** head)
{
    list_node_t** phead = head;

    printf("{ ");
    while (*phead != NULL) {
        printf("%d, ", (*phead)->value);
        phead = &(*phead)->next;
    }

    puts("}");

}
