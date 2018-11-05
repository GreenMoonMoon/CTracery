// Port of Tracery
// Original author: Kate Compton
#ifndef __TRACERY__
#define __TRACERY__

#include "utils.h"

typedef struct Symbol
{
    char *name;
    char **rules;
    int ruleCount;
} Symbol;

typedef struct Trace
{
    int placeholder;
} Trace;

typedef struct Grammar
{
    /*The symbols are first allocated in the Grammar struct, then their
    pointer is passed to the */
    Symbol *symbols;
    int count;
    int capacity;
} Grammar;

Grammar *CreateGrammar();
void FreeGrammar(Grammar *grammar);

Trace *CreateTrace(Grammar *grammar); //Create Trace from "origin" symbol
Trace *CreateTraceFromSymbol(Grammar *grammar, Symbol *symbol);
char *CreateFlattenedTrace(Grammar *grammar);
void AddSymbolToGrammar(Grammar *grammar, char *symbolName);
Symbol *GetSymbolFromGrammar(Grammar *grammar, char *symbolName);
void PushRuleToGrammar(Grammar *grammar, char *symbolName, char **rules);
char **PopRuleFromGrammar(Grammar *grammar, char *symbolName);

void FreeTrace(Trace *trace);
void ExpandTrace(Trace *trace);
char *FlattenTrace(Trace *trace);

Symbol *LoadSymbolFromString(char* symbolStr);

#endif