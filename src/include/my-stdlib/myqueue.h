
#pragma once

#include <stddef.h>
#include <stdint.h>


typedef struct MyQueueInt32 {
    size_t capacity;
    size_t size;
    size_t front;
    int32_t *items;
} MyQueueInt32;

MyQueueInt32 *
myqueue_int32_new(void);

void
myqueue_int32_del(MyQueueInt32 *queue);

size_t
myqueue_int32_size(MyQueueInt32 *queue);

void
myqueue_int32_add(MyQueueInt32 *queue, int32_t val);

int32_t
myqueue_int32_remove(MyQueueInt32 *queue);

int32_t
myqueue_int32_front(MyQueueInt32 *queue);

