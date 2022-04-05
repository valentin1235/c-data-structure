#include "queue.h"

void enqueue(myqueue_t* queue, int value)
{
    assert(queue->value_count < QUEUE_SIZE);

    queue->values[queue->back] = value;

    queue->back = (queue->back + 1) % QUEUE_SIZE;

    ++queue->value_count;

    printf("[enqueue] front:%d, back:%d, count:%d\n", queue->front, queue->back, queue->value_count);
}

int dequeue(myqueue_t* queue)
{
    int ret;

    assert(queue->value_count >= 1);

    ret = queue->values[queue->front];

    queue->front = (queue->front + 1) % QUEUE_SIZE;

    --queue->value_count;

    printf("[dequeue] front:%d, back:%d, count:%d, ret:%d\n", queue->front, queue->back, queue->value_count, ret);

    return ret;
}
