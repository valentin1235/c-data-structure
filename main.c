#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"

enum { NAME_LEN = 32 };

static void linkedlist_test(void)
{
    node_t* head = NULL;

    add_ordered(&head, 100);
    add_ordered(&head, 200);
    add_ordered(&head, 150);
    add_ordered(&head, 50);
    print_node(&head);

    assert(add_at(&head, 5, 124) == FALSE);
    assert(add_at(&head, 4, 124) == TRUE);

    print_node(&head);

    remove_at(&head, 1);
    print_node(&head);

    remove_last(&head);
    remove_last(&head);
    remove_last(&head);
    remove_last(&head);
    
    print_node(&head);

    assert(remove_last(&head) == FALSE);
    assert(head == NULL);
}


int main(void)
{
    linkedlist_test();

    return 0;
}
