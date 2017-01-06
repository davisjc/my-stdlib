
#pragma once

#include <stddef.h>


void *
myalloc_calloc(size_t nitems, size_t size);

void
myalloc_free(void *ptr);

void *
myalloc_malloc(size_t size);

void *
myalloc_realloc(void *ptr, size_t size);

