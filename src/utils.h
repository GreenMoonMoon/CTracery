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

void *Reallocate(void *previous, size_t capacity);

char *ReadGrammarFile(const char *filepath);

void *AddPair(Map *map, const char *key, void *value);
// void *ModifyPair(Map *map, const char *key, void *value);
// void RemovePair(Map *map, const char *key);
void  *Lookup(Map *map, const char *key);

#endif