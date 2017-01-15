
#include <my-stdlib/myqueue.h>

#include <my-stdlib/myalloc.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define MYQUEUE_INIT_CAPACITY 16


MyQueueInt32 *
myqueue_int32_new(void)
{
    MyQueueInt32 *queue = (MyQueueInt32 *)mycalloc(1, sizeof(*queue));
    queue->capacity = MYQUEUE_INIT_CAPACITY;
    queue->items = (int32_t *)mycalloc(queue->capacity,
                                       sizeof(*(queue->items)));

    return queue;
}

void
myqueue_int32_del(MyQueueInt32 *queue)
{
    myfree(queue->items);
    myfree(queue);
}

size_t
myqueue_int32_size(MyQueueInt32 *queue)
{
    return queue->size;
}

void
myqueue_int32_add(MyQueueInt32 *queue, int32_t val)
{
    if (queue->size + 1 > queue->capacity) {
        size_t back = (queue->front + queue->size - 1) % queue->capacity;
        size_t prevcapacity = queue->capacity;
        queue->capacity *= 2;
        queue->items = (int32_t *)myrealloc(queue->items,
                                            sizeof(*(queue->items))
                                            * queue->capacity);

        if (back < queue->front) {
            memcpy(queue->items + prevcapacity, queue->items,
                   sizeof(*(queue->items)) * (back + 1));
        }
    }

    size_t back_new = (queue->front + queue->size) % queue->capacity;

    queue->items[back_new] = val;
    queue->size++;
}

int32_t
myqueue_int32_remove(MyQueueInt32 *queue)
{
    int32_t val = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return val;
}

int32_t
myqueue_int32_front(MyQueueInt32 *queue)
{
    return queue->items[queue->front];
}

