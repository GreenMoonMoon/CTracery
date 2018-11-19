#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "tracery.h"

Grammar *CreateGrammar()
{
    //Represent a grammar object on the heap. hold arrays of symbols and rules
    //to flatten.
    Grammar *newGrammar = malloc(sizeof(Grammar));
    if (newGrammar == NULL)
        exit(-1);

    newGrammar->capacity = 0;
    newGrammar->count = 0;
    newGrammar->symbols = NULL;

    return newGrammar;
}

Grammar *CreateGrammarFromStream(char *filepath)
{
    return NULL;
}

void FreeGrammar(Grammar *grammar)
{
    //Make sure to free any structure within grammar.
    int i;
    for (i = 0; i < grammar->count; i++)
        FreeSymbol(&grammar->symbols[i]);
    free(grammar);
}

char *FlattenGrammar(Grammar *grammar)
{
    return "";
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

// char *CreateFlattenedTrace(Grammar *grammar)
// {
//     Trace *trace = CreateTrace(grammar);
//     char *flattened = FlattenTrace(trace);
//     FreeTrace(trace);
//     return flattened;
// }

Symbol *AddSymbolToGrammar(Grammar *grammar, char *symbolName)
{
    //implemented using http://www.craftinginterpreters.com/chunks-of-bytecode.html
    if (grammar->count == grammar->capacity)
    {
        grammar->capacity = GROW_CAPACITY(grammar->capacity);
        grammar->symbols = GROW_ARRAY(grammar->symbols, Symbol, grammar->capacity);
    }

    grammar->symbols[grammar->count] = (Symbol){.name = symbolName, .rules = NULL, .count = 0};
    Symbol *symbol = &grammar->symbols[++grammar->count];
    return symbol;
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
    Symbol *symbol = AddSymbolToGrammar(grammar, symbolName);
    return symbol;
}

void PushRulesToGrammar(Grammar *grammar, char *symbolName, char **rules, int count)
{
    //TODO: currently each set of rules for symbols is stored somewhere on the
    //stack. They should be all part of a single rules location in the heap,
    //since a lot of these rules will be processed at the same time.
    //TODO: The creation of symbol and theirs rules are done trought two
    //separate process, however a symbol without rules is an exception, rules
    //should be instanciated with the symbol.
    Symbol *symbol = GetSymbolFromGrammar(grammar, symbolName);
    if (symbol != NULL)
    {
        symbol->rules = rules;
        symbol->count = count;
    }
}

char **PopRulesFromGrammar(Grammar *grammar, char *symbolName)
{
    Symbol *symbol = GetSymbolFromGrammar(grammar, symbolName);
    if (symbol != NULL)
        return symbol->rules;
    return NULL;
}

char **GetRuleFromGrammar(Grammar *grammar, char *symbolName)
{
    Symbol *symbol = GetSymbolFromGrammar(grammar, symbolName);
    if (symbol == NULL)
        return NULL;

    char **rule = GetRuleFromSymbol(symbol);
    if (rule == NULL)
        return NULL;

    return rule;
}

void FreeTrace(Trace *trace)
{
    //free innards of trace ...
    free(trace);
}

void ExpandTrace(Trace *trace)
{
}

void FreeSymbol(Symbol *symbol)
{
    int i;
    for (i = 0; i < symbol->count; i++)
    {
        free(symbol->rules[i]);
    }

    free(symbol);
}

char **GetRuleFromSymbol(Symbol *symbol)
{
    if (symbol->count > 0)
        return &symbol->rules[0];
    return NULL;
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

char *ReadGrammarFile(const char *filepath)
{
    //Reads the grammar file are allocate the content on the heap.
    //Returns a pointer to the string.
    FILE *stream = fopen(filepath, "r");
    fseek(stream, 0, SEEK_END);
    long fileSize = ftell(stream);
    fseek(stream, 0, SEEK_SET);

    char *grammarRaw = malloc(fileSize + 1);
    if (grammarRaw == NULL)
        exit(-1);

    size_t successfully_read = fread(grammarRaw, 1, fileSize, stream);
    if (successfully_read != fileSize)
        exit(-1);

    int closed = fclose(stream);
    if (closed != 0)
        exit(-1);

    grammarRaw[fileSize] = 0;

    return grammarRaw;
}