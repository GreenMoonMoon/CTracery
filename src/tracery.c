#include <errno.h>
#include <stdlib.h>

#include "tracery.h"

Tracery *NewTracery()
{
    // struct TraceryParser *newTracery = (struct TraceryParser *)malloc(sizeof(struct TraceryParser));
    Tracery *newTracery = malloc(sizeof(Tracery));
    if (newTracery == NULL)
    {
        exit(-1);
    }

    (*newTracery).Parse = ParseFunc;
    (*newTracery).ParseTag = ParseTagFunc;
    (*newTracery).Destroy = DestroyTraceryFunc;

    return newTracery;
}

static void DestroyTraceryFunc(Tracery *tracery)
{
    // for struct in struct array, free the struct content.
}

void FreeTracery(Tracery *tracery)
{
    tracery->Destroy(tracery);
    free(tracery);
}

void ParseFunc(char *string, int stringSize)
{
}

void ParseTagFunc(char *string, int stringSize)
{
}

Grammar *NewGrammar()
{
    Grammar *newGrammar = malloc(sizeof(Grammar));
    if (newGrammar == NULL)
    {
        exit(-1);
    }

    (*newGrammar).selected = 0;
    (*newGrammar).Destroy = DestroyGrammarFunc;

    return newGrammar;
}

static void DestroyGrammarFunc(Grammar *grammar)
{
    // for struct in struct array, free the struct content.
}

void FreeGrammar(Grammar *grammar)
{
    grammar->Destroy(grammar);
    free(grammar);
}