#include <stdio.h>
#include <errno.h>

#include "tracery.h"

struct TraceryParser *NewParser()
{
    void *newParser = (struct TraceryParser *)malloc(sizeof(struct TraceryParser));
    if (newParser == NULL)
    {
        exit(-1);
    }

    // newParser->Parse = FreeParser;

    return newParser;
}

void FreeParser(struct TraceryParser *parser)
{
}

void ParseFunc(char *string)
{
}

void ParseTagFunc(char *string)
{
}
