#ifndef __TRACERY_UTILS__
#define __TRACERY_UTILS__

#include <stdlib.h>
#include <stdio.h>

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)
#define GROW_ARRAY(previous, type, capacity) \
    (type *)Reallocate(previous, sizeof(type) * (capacity))

typedef struct Map
{
    unsigned int capacity;
    unsigned int count;
    void **pairs;
} Map;

void *AddPair(Map *map, const char *key, void *value);
void *Lookup(Map *map, const char *key);

void *Reallocate(void *previous, size_t capacity);

char *ReadStream(FILE *stream);

#endif