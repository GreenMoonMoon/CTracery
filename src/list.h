//Simple dynamic list

#ifndef __LIST__
#define __LIST__

#include <stdlib.h>

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)
#define GROW_ARRAY(previous, type, oldCapacity, newCapacity) \
    (type *)Reallocate(previous, sizeof(type) * (oldCapacity), sizeof(type) * (newCapacity))
#define FREE_ARRAY(type, pointer, oldCapacity) \
    Reallocate(pointer, sizeof(type) * (oldCapacity), 0)

void *Reallocate(void *previous, size_t oldCapacity, size_t newCapacity);

#endif