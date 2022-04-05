#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <assert.h>

#define QUEUE_SIZE (10)

typedef struct myqueue {
    int front;
    int back;
    size_t value_count;
    int values[QUEUE_SIZE];
} myqueue_t;

void enqueue(myqueue_t* queue, int value);
int dequeue(myqueue_t* queue);

#endif /* QUEUE_H */
