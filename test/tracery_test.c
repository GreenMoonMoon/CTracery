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
    //Symbol *symbol = GetSymbolFromGrammar(grammar, symbolName);
    

    char *rules[1] = {"test phrase"};
    PushRuleToGrammar(grammar, symbolName, rules);

    char **popedRules = PopRuleFromGrammar(grammar, symbolName);
    _assert(popedRules);

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

int all_tests()
{
    // _verify(TestParse);
    _verify(TestGrammar);
    _verify(TestRules);
    _verify(TestTrace);
    _verify(TestTraceFromSymbol);
    _verify(TestCreateFlattened);

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