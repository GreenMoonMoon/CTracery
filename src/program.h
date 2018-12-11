#ifndef __PROGRAM__
#define __PROGRAM__

//Operation code for the bytecode ... code.
typedef enum
{
    OP_RETURN
} OpCode;

typedef struct Chunk
{
    unsigned int *codes;
    int count;
    int capacity;
} Chunk;

void InitChunk(Chunk *chunk);
void FreeChunk(Chunk *chunk);
void WriteChunk(Chunk *chunk, unsigned int code);

#endif
