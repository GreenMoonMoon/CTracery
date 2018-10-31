#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "tracery.h"

// Tracery *NewTracery()
// {
//     // struct TraceryParser *newTracery = (struct TraceryParser *)malloc(sizeof(struct TraceryParser));
//     Tracery *newTracery = malloc(sizeof(Tracery));
//     if (newTracery == NULL)
//     {
//         exit(1);
//     }

//     (*newTracery).Parse = ParseFunc;
//     // (*newTracery).ParseTag = ParseTagFunc;
//     (*newTracery).ParseSymbol = ParseSymbolFunc;
//     (*newTracery).Destroy = DestroyTraceryFunc;

//     return newTracery;
// }

// static void DestroyTraceryFunc(Tracery *tracery)
// {
//     // for struct in struct array, free the struct content.
// }

// void FreeTracery(Tracery *tracery)
// {
//     tracery->Destroy(tracery);
//     free(tracery);
// }

// char **ParseFunc(char *string, int *sectionCount)
// {
//     //Separate tag tokens.
//     //The result should be an array of tag token an in between bits.
//     //?? use pointer to parts of the original string.

//     *sectionCount = 0;
//     int stringSize = strlen(string);
//     if (!stringSize)
//         return NULL;

//     int i = 0;
//     for (; i < stringSize; i++)
//     {
//         switch (string[i])
//         {
//         case '#':
//             if(i + 1 < stringSize)
//                 *sectionCount += 1;

//         }
//     }void Expand(Trace *trace);

//     char **sections = NULL;
//     return sections;
// }

// // void ParseTagFunc(char *string, int stringSize)
// void ParseSymbolFunc(char *string, int stringSize)
// {
// }

Grammar *CreateGrammar()
{
    Grammar *newGrammar = malloc(sizeof(Grammar));
    if (newGrammar == NULL)
        exit(-1);

    return newGrammar;
}

void FreeGrammar(Grammar *grammar)
{
    //free innards of grammar ...
    free(grammar);
}

Trace *CreateTrace(Grammar *grammar)
{
    Trace *newTrace = malloc(sizeof(Trace));
    if (newTrace == NULL)
        exit(-1);

    return newTrace;
}

void FreeTrace(Trace *trace)
{
    //free innards of trace ...
    free(trace);
}

void ExpandTrace(Trace *trace)
{
}

void FlattenTrace(Trace *trace)
{
}
