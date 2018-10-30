#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "tracery.h"

Tracery *NewTracery()
{
    // struct TraceryParser *newTracery = (struct TraceryParser *)malloc(sizeof(struct TraceryParser));
    Tracery *newTracery = malloc(sizeof(Tracery));
    if (newTracery == NULL)
    {
        exit(1);
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

char **ParseFunc(char *string, int *sectionCount)
{
    //This function will keep the rule as is and return only pointers
    //to each valid subsections.
    int stringSize = strlen(string);
    if (!stringSize)
        return NULL;

    char **sections = malloc(sizeof(char*) * 1);
    if(sections == NULL)
        exit(1);
    
    int index;
    for (index = 0; index < stringSize; index++)
    {
        switch(string[index])
        {
            case '[':
            break;
            case ']':
            break;
            case '#':
            break;
        }
    }

    sectionCount = 0;
    sections[0] = string;

    return sections;
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