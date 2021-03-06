
#include <my-stdlib/mystack.h>

#include <stddef.h>
#include <stdint.h>

#include <my-stdlib/myalloc.h>

#define MYSTACK_INIT_CAPACITY 16


MyStackInt32 *
mystack_int32_new(void)
{
    MyStackInt32 *stack = (MyStackInt32 *)mycalloc(1, sizeof(*stack));
    stack->capacity = MYSTACK_INIT_CAPACITY;
    stack->items = (int32_t *)mycalloc(stack->capacity,
                                       sizeof(*(stack->items)));
    return stack;
}

void
mystack_int32_del(MyStackInt32 *stack)
{
    myfree(stack->items);
    myfree(stack);
}

size_t
mystack_int32_size(MyStackInt32 *stack)
{
    return stack->size;
}

void
mystack_int32_push(MyStackInt32 *stack, int32_t val)
{
    if (stack->size > stack->capacity - 1) {
        stack->capacity *= 2;
        stack->items = (int32_t *)myrealloc(stack->items,
                                            sizeof(*(stack->items))
                                            * stack->capacity);
    }

    stack->items[stack->size++] = val;
}

int32_t
mystack_int32_pop(MyStackInt32 *stack)
{
    return stack->items[--stack->size];
}

int32_t
mystack_int32_peek(MyStackInt32 *stack)
{
    return stack->items[stack->size - 1];
}

