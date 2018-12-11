#include <stdbool.h>
#include <stdio.h>

#include "program.h"
#include "list.h"

int main(int argc, const char *argv[])
{
    Chunk *c = &(Chunk){.codes = NULL, .count = 0, .capacity = 0};
    InitChunk(c);
    WriteChunk(c, 1);
    WriteChunk(c, 2);
    WriteChunk(c, 3);
    WriteChunk(c, 4);
    WriteChunk(c, 5);
    WriteChunk(c, 6);
    WriteChunk(c, 7);
    WriteChunk(c, 8);
    WriteChunk(c, 9);
    WriteChunk(c, 10);
    WriteChunk(c, 11);
    WriteChunk(c, 12);
    WriteChunk(c, 13);
    WriteChunk(c, 14);
    WriteChunk(c, 15);
    WriteChunk(c, 16);

    printf("current count:%d\n", c->count);
    printf("chunk[0]:%d\n", c->codes[0]);
    printf("chunk[15]:%d\n", c->codes[15]);

    return 0;
}

void InitChunk(Chunk *chunk)
{
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->codes = NULL;
}

void FreeChunk(Chunk *chunk)
{
    FREE_ARRAY(unsigned int, chunk, chunk->capacity);
    InitChunk(chunk);
}

void WriteChunk(Chunk *chunk, unsigned int code)
{
    if (chunk->count >= chunk->capacity)
    {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(chunk->capacity);
        chunk->codes = GROW_ARRAY(chunk->codes, unsigned int, oldCapacity, chunk->capacity);
    }

    chunk->codes[chunk->count++] = code;
    // chunk->count++;
}

void *Reallocate(void *previous, size_t oldCapacity, size_t newCapacity)
{
    if (newCapacity == 0)
    {
        free(previous);
        return NULL;
    }

    return realloc(previous, newCapacity);
}
