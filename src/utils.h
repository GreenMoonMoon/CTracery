#ifndef __TRACERY_UTILS__
#define __TRACERY_UTILS__

#include <stdlib.h>

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)
#define GROW_ARRAY(previous, type, capacity) \
    (type *)reallocate(previous, sizeof(type) * (capacity))

void* reallocate(void* previous, size_t capacity);

#endif