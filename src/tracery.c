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

    newGrammar->capacity = 0;
    newGrammar->count = 0;
    newGrammar->symbols = NULL;

    return newGrammar;
}

void FreeGrammar(Grammar *grammar)
{
    //Make sure to free any structure within grammar.
    int i;
    for(i = 0; i < grammar->count; i++)
        FreeSymbol(&grammar->symbols[i]);
    free(grammar);
}

Trace *CreateTrace(Grammar *grammar)
{
    //Create a trace from 'origin' symbol
    Trace *newTrace = malloc(sizeof(Trace));
    if (newTrace == NULL)
        exit(-1);

    return newTrace;
}

Trace *CreateTraceFromSymbol(Grammar *grammar, Symbol *symbol)
{
    Trace *newTrace = malloc(sizeof(Trace));
    if (newTrace == NULL)
        exit(-1);

    return newTrace;
}

char *CreateFlattenedTrace(Grammar *grammar)
{
    Trace *trace = CreateTrace(grammar);
    char *flattened = FlattenTrace(trace);
    FreeTrace(trace);
    return flattened;
}

void AddSymbolToGrammar(Grammar *grammar, char *symbolName)
{
    //implemented using http://www.craftinginterpreters.com/chunks-of-bytecode.html
    if (grammar->count == grammar->capacity)
    {
        grammar->capacity = GROW_CAPACITY(grammar->capacity);
        grammar->symbols = GROW_ARRAY(grammar->symbols, Symbol, grammar->capacity);
    }

    grammar->symbols[grammar->count] = (Symbol){.name = symbolName};
    grammar->count++;
}

Symbol *GetSymbolFromGrammar(Grammar *grammar, char *symbolName)
{
    //This is quite linear: O(n) type of search.
    //Using a hash table migth save more time but will require change to
    //the structure.
    int i;
    for (i = 0; i < grammar->count; i++)
    {
        if (grammar->symbols[i].name == symbolName)
            return grammar->symbols;
    }
    return NULL;
}

void PushRuleToGrammar(Grammar *grammar, char *symbolName, char **rules)
{
    Symbol *symbol = GetSymbolFromGrammar(grammar, symbolName);
    if (symbol != NULL)
        symbol->rules = rules;
}

char **PopRuleFromGrammar(Grammar *grammar, char *symbolName)
{
    int i;
    for(i =0; i < grammar->count; i++)
    {
        if(grammar->symbols[i].name == symbolName)
            return grammar->symbols[i].rules;
    }
    return NULL;
}

void FreeTrace(Trace *trace)
{
    //free innards of trace ...
    free(trace);
}

void ExpandTrace(Trace *trace)
{
}

char *FlattenTrace(Trace *trace)
{
    return "";
}

void FreeSymbol(Symbol *symbol)
{
    int i;
    for(i=0; i< symbol->ruleCount; i++)
        free(symbol->rules[i]);
    free(symbol);
}

void *reallocate(void *previous, size_t capacity)
{
    if (capacity == 0)
    {
        free(previous);
        return NULL;
    }

    return realloc(previous, capacity);
}