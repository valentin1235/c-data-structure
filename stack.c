#include "stack.h"
#include <assert.h>

void push(mystack_t* stack, int value)
{
    assert(stack->values != NULL);
    assert(stack->value_count < STACK_SIZE);

    stack->values[(stack->value_count)++] = value;
}

int pop(mystack_t* stack)
{
    assert(stack->values != NULL);
    assert(stack->value_count != 0);

    return stack->values[--(stack->value_count)];
}
