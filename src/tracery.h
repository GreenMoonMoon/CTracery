// Port of Tracery
// Original author: Kate Compton
#ifndef __TRACERY__
#define __TRACERY__

#include "utils.h"
#include "parser.h"

extern const char *_delimiters;

enum TokenType
{
    SYMBOL,
    TEXT,
    RULE,
    EOR //End of rule
};

typedef struct Token
{
    void *data;
    enum TokenType type;
} Token;

typedef struct Text
{
    char *start;
    size_t length;
} Text;

typedef struct Rule
{
    Token *tokens;
    int count;
} Rule;

typedef struct Symbol
{
    char *key;
    Rule *rules;
    int count;
} Symbol;

typedef struct Grammar
{
    Rule *rules;
    Rule *origin;
    unsigned int count;
    unsigned int capacity;
} Grammar;

Grammar *CreateGrammar();
Grammar *CreateGrammarFromStream(FILE *stream);
void FreeGrammar(Grammar *grammar);
void FreeRule(Rule *rule);
void FreeSymbol(Symbol *symbol);
char *FlattenRule(Rule *rule);

int ScanRule(Grammar *grammar, char *rule);

// void *AddSymbol(Grammar *grammar, char *symbolName);
// Symbol *GetSymbolFromGrammar(Grammar *grammar, char *symbolName);
// void PushRulesToGrammar(Grammar *grammar, char *symbolName, char **rules, int rulesCount);
// char **PopRulesFromGrammar(Grammar *grammar, char *symbolName);
// char **GetRuleFromGrammar(Grammar *grammar, char *symbolName);

// Symbol *LoadSymbolFromString(char *symbolStr);
// char **GetRuleFromSymbol(Symbol *symbol);

#endif