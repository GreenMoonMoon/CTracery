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
    RULE,
    EOR //End of rule
};

typedef struct Token
{
    void* data;
    enum TokenType type;
} Token;

typedef struct Text
{
    char *string;
    int start, end;
} Text;

typedef struct Rule
{
    Token *tokens;
    int count;
} Rule;

typedef struct Symbol
{
    Rule *rules;
    int count;
} Symbol;

typedef struct Grammar
{
    Symbol *symbols;
    Rule *origin;
    int count;
    int capacity;
} Grammar;

Grammar *CreateGrammar();
Grammar *CreateGrammarFromStream();
void FreeGrammar(Grammar *grammar);
void FreeSymbol(Symbol *symbol);
char *FlattenGrammar(Grammar *Grammar);

// void *AddSymbol(Grammar *grammar, char *symbolName);
// Symbol *GetSymbolFromGrammar(Grammar *grammar, char *symbolName);
// void PushRulesToGrammar(Grammar *grammar, char *symbolName, char **rules, int rulesCount);
// char **PopRulesFromGrammar(Grammar *grammar, char *symbolName);
// char **GetRuleFromGrammar(Grammar *grammar, char *symbolName);

// Symbol *LoadSymbolFromString(char *symbolStr);
// char **GetRuleFromSymbol(Symbol *symbol);

#endif