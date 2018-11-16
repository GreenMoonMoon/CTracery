// Port of Tracery
// Original author: Kate Compton
#ifndef __TRACERY__
#define __TRACERY__

#include "utils.h"

enum TokenType
{
    SYMBOL,
    TEXT,
    ACTION,
    EOR //End of rule
};

typedef struct Token
{
    enum TokenType type;
    // char *raw;
} Token;

typedef struct Rule
{
    Token *tokens;
} Rule;

typedef struct Symbol
{
    char *name;
    Rule *rules;
    int count;
} Symbol;

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
void FreeGrammar(Grammar *grammar);

Trace *CreateTrace(Grammar *grammar); //Create Trace from "origin" symbol
Trace *CreateTraceFromSymbol(Grammar *grammar, Symbol *symbol);
char *CreateFlattenedTrace(Grammar *grammar);
void AddSymbolToGrammar(Grammar *grammar, char *symbolName);
Symbol *GetSymbolFromGrammar(Grammar *grammar, char *symbolName);
void PushRulesToGrammar(Grammar *grammar, char *symbolName, Rule *rules, int rulesCount);
Rule *PopRulesFromGrammar(Grammar *grammar, char *symbolName);
Rule *GetRuleFromGrammar(Grammar *grammar, char *symbolName);

void FreeTrace(Trace *trace);
void ExpandTrace(Trace *trace);
char *FlattenTrace(Trace *trace);

Symbol *LoadSymbolFromString(char *symbolStr);
void FreeSymbol(Symbol *symbol);
Rule *GetRuleFromSymbol(Symbol *symbol);
 
#endif