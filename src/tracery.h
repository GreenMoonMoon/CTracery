// Port of Tracery
// Original author: Kate Compton
#ifndef __TRACERY__
#define __TRACERY__

#include "utils.h"
#include "parser.h"

enum TokenType
{
    SYMBOL,
    TEXT,
    ACTION,
    EOR //End of rule
};

typedef struct Symbol
{
    void *tokens;
    int count;
} Symbol;

typedef struct Text
{
    char *string;
    int start, end;
} Text;

// typedef struct Symbol
// {
//     char *name;
//     char **rules;
//     int count;
// } Symbol;

typedef struct Trace
{
    int placeholder;
} Trace;

typedef struct Grammar
{
    //The symbols are first allocated in the Grammar struct, then their
    //pointer is passed to the
    Symbol *symbols;
    int count;
    int capacity;
} Grammar;

Grammar *CreateGrammar();
Grammar *CreateGrammarFromStream();
void FreeGrammar(Grammar *grammar);
char *FlattenGrammar(Grammar *Grammar);

void *AddSymbol(Grammar *grammar, char *symbolName);
Trace *CreateTrace(Grammar *grammar); //Create Trace from "origin" symbol
Trace *CreateTraceFromSymbol(Grammar *grammar, Symbol *symbol);
// char *CreateFlattenedTrace(Grammar *grammar);
Symbol *GetSymbolFromGrammar(Grammar *grammar, char *symbolName);
void PushRulesToGrammar(Grammar *grammar, char *symbolName, char **rules, int rulesCount);
char **PopRulesFromGrammar(Grammar *grammar, char *symbolName);
char **GetRuleFromGrammar(Grammar *grammar, char *symbolName);

void FreeTrace(Trace *trace);
void ExpandTrace(Trace *trace);

Symbol *LoadSymbolFromString(char *symbolStr);
void FreeSymbol(Symbol *symbol);
char **GetRuleFromSymbol(Symbol *symbol);

#endif