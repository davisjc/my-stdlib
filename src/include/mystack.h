
#pragma once

#include <stddef.h>
#include <stdint.h>


typedef struct MyStackInt32 {
    size_t capacity;
    size_t size;
    int32_t *items;
} MyStackInt32;

MyStackInt32 *
mystack_int32_new(void);

void
mystack_int32_del(MyStackInt32 *stack);

size_t
mystack_int32_size(MyStackInt32 *stack);

void
mystack_int32_push(MyStackInt32 *stack, int32_t val);

int32_t
mystack_int32_pop(MyStackInt32 *stack);

int32_t
mystack_int32_peek(MyStackInt32 *stack);

