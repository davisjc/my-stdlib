
#include <my-stdlib/myalloc.h>

#include <stddef.h>
#include <stdlib.h>


void *
myalloc_calloc(size_t nitems, size_t size)
{
    return calloc(nitems, size);
}

void
myalloc_free(void *ptr)
{
    free(ptr);
}

void *
myalloc_malloc(size_t size)
{
    return malloc(size);
}

void *
myalloc_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

