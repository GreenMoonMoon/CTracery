#include <stdio.h>

#include "unittest.h"
#include "../src/tracery.h"

int TestParse()
{
    int testStringsCount = 17;
    char *testStrings[] = {
        "",
        "fooo",
        "#someSymbol# and #someOtherSymbol#",
        "####",
        "#[]#[]##",
        "#someOtherSymbol.cap.pluralize#",
        "#[#do some things#]symbol.mod[someotherthings[and a function]]#",
        "#[fxn][fxn][fxn[subfxn]]symbol[[fxn]]#",
        "#[fxn][#fxn#][fxn[#subfxn#]]symbol[[fxn]]#",
        "#hero# ate some #color# #animal.s#",
        "#[#setPronouns#][#setOccupation#][hero:#name#]story#",
        "#hero# ate some #color# #animal.s#",
        "#someSymbol# and #someOtherSymbol",
        "#[fxn][fxn][fxn[subfxn]]symbol[fxn]]#"};

    // "[action]symbol.mod1.mod2[postAction]",
    // "stuff[action]symbol.mod1.mod2[postAction]",
    // "[action]symbol.mod1.mod2[postAction]stuff"};

    Grammar *grammar = CreateGrammar();
    int i;
    for (i = 0; i < testStringsCount; i++)
    {
        AddSymbolToGrammar(grammar, testStrings[i]);
    }

    FreeGrammar(grammar);

    return 0;
}

int TestGrammar()
{
    Grammar *grammar = CreateGrammar();

    char *symbolName = "origin";
    AddSymbolToGrammar(grammar, symbolName);
    _assert(grammar->symbols);
    Symbol *symbol = GetSymbolFromGrammar(grammar, symbolName);
    _assertEqualValue(symbol->name, "origin");

    return 0;
}

int TestRules()
{
    Grammar *grammar = CreateGrammar();

    char *symbolName = "origin";
    AddSymbolToGrammar(grammar, symbolName);

    Token tokens[2] = {{TEXT}, {TEXT}};
    Rule rules[1] = {{.tokens = &tokens[0]}};
    PushRulesToGrammar(grammar, symbolName, rules, 1);

    // Rule *popedRules = PopRulesFromGrammar(grammar, symbolName);
    // _assert(popedRules);

    FreeGrammar(grammar);

    return 0;
}

int TestTrace()
{
    Grammar *grammar = CreateGrammar();

    // "origin:[\"test phrase\"]"
    char *symbolName = "origin";
    AddSymbolToGrammar(grammar, symbolName);
    _assert(grammar->symbols);
    Symbol *symbol = GetSymbolFromGrammar(grammar, symbolName);
    _assertEqualValue(symbol->name, "origin");

    Trace *trace = CreateTrace(grammar);
    ExpandTrace(trace);
    char *flattened = FlattenTrace(trace);

    FreeTrace(trace);
    FreeGrammar(grammar);

    return 0;
}

int TestTraceFromSymbol()
{
    Grammar *grammar = CreateGrammar();
    //create rules ...
    Trace *trace = CreateTrace(grammar);
    ExpandTrace(trace);
    char *flattened = FlattenTrace(trace);

    FreeTrace(trace);
    FreeGrammar(grammar);

    return 0;
}

int TestCreateFlattened()
{
    Grammar *grammar = CreateGrammar();
    //create rules ...
    char *flattened = CreateFlattenedTrace(grammar);

    FreeGrammar(grammar);

    return 0;
}

// int TestReadGrammarFile()
// {
//     //setup the test by creating a temp file
//     const char *filepath;
//     char *grammarRaw = ReadGrammarFile(filepath);

//     free(grammarRaw);
//     //tear down the test by deleting the temp file

//     return 0;
// }

int TestExpandGrammar()
{
    return 0;
}

int TestFlattenGrammar()
{
    return 0;
}

int all_tests()
{
    // _verify(TestParse);
    _verify(TestGrammar);
    _verify(TestRules);
    // _verify(TestTrace);
    // _verify(TestTraceFromSymbol);
    // _verify(TestCreateFlattened);
    // _verify(TestReadGrammarFile);
    // _verify(TestExpandGrammar);
    // _verify(TestFlattenGrammar);

    return 0;
}

int main(int argc, char const *argv[])
{
    int result = all_tests();
    if (result == 0)
        printf("PASSED\n");
    printf("Tests run: %d\n", tests_run);
    return 0;
}