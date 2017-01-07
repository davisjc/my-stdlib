
#include <my-stdlib/myalloc.h>

#include <stddef.h>
#include <stdlib.h>


void *
mycalloc(size_t nitems, size_t size)
{
    return calloc(nitems, size);
}

void
myfree(void *ptr)
{
    free(ptr);
}

void *
mymalloc(size_t size)
{
    return malloc(size);
}

void *
myrealloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

