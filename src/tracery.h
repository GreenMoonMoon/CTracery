// Port of Tracery
// Original author: Kate Compton
#ifndef __TRACERY__
#define __TRACERY__

#include "utils.h"

// struct Action
// {
//     int selected;
// };

// struct Symbol
// {
//     int selected;
// };

// struct Modifier
// {
//     int selected;
// };

// typedef struct TraceryOBJ
// {
//     struct Action *preActions;
//     struct Action *postActions;
//     struct Symbol *symbols;
//     struct Modifier *mods;
// } TraceryOBJ;

// typedef struct Tracery
// {
//     //General struct used to access Tracery specific functions.
//     //TODO: check if such container is actually usefull, it might be better
//     //to leave all the function in the open with meaningfull name to avoid
//     //collision.
//     char **(*Parse)(char *string, int *coun);
//     // void (*ParseTag)(char *string, int stringSize);
//     void (*ParseSymbol)(char *string, int stringSize);
//     void (*Destroy)();
// } Tracery;

// Tracery *NewTracery();
// static void DestroyTraceryFunc(Tracery *tracery);
// void FreeTracery(Tracery *tracery);

// char **ParseFunc(char *string, int *coun);
// // void ParseTagFunc(char *string, int stringSize);
// void ParseSymbolFunc(char *string, int stringSize);

typedef struct Symbol
{
    char *name;
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


void FreeTrace(Trace *trace);
void ExpandTrace(Trace *trace);
char *FlattenTrace(Trace *trace);

Symbol *LoadSymbolFromString(char* symbolStr);

#endif