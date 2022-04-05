#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define STACK_SIZE (10)

typedef struct {
    size_t value_count;
    int values[STACK_SIZE];
} mystack_t;

void push(mystack_t* stack, int value);
int pop(mystack_t* stack);

#endif /* STACK_H */
