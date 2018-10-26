#include <errno.h>
#include <stdlib.h>

#include "tracery.h"

typedef struct TraceryParser tracery;

tracery *NewTracery()
{
    // struct TraceryParser *newTracery = (struct TraceryParser *)malloc(sizeof(struct TraceryParser));
    tracery *newTracery = malloc(sizeof(struct TraceryParser));
    if (newTracery == NULL)
    {
        exit(-1);
    }

    (*newTracery).Parse = ParseFunc;
    (*newTracery).ParseTag = ParseTagFunc;
    (*newTracery).Free = FreeTraceryFunc;

    return newTracery;
}

void ParseFunc(char *string)
{
}

void ParseTagFunc(char *string)
{
}

void FreeTraceryFunc(struct TraceryParser *parser)
{
}