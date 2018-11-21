#include <stdio.h>
#include <string.h>

#include "unittest.h"
#include "../src/tracery.h"

// int TestParsesActions()
// {
//     int testTextBCount = 13;
//     char *testTextB[13] = {
//         "#hero# ate some #color# #animal.s#",
//         "#someOtherSymbol.cap.pluralize#",
//         "#[]#[]##",
//         "#[#do some things#]symbol.mod[someotherthings[and a function]]#",
//         "#[fxn][fxn][fxn[subfxn]]symbol[[fxn]]#",
//         "#[fxn][#fxn#][fxn[#subfxn#]]symbol[[fxn]]#",
//         "#[#setPronouns#][#setOccupation#][hero:#name#]story#",
//         "#[fxn][fxn][fxn[subfxn]]symbol[fxn]]#",
//         "[action]symbol.mod1.mod2[postAction]",
//         "stuff[action]symbol.mod1.mod2[postAction]",
//         "[action]symbol.mod1.mod2[postAction]stuff"
//     };

//     Grammar *grammar = CreateGrammar();
//     char *ruleA[1] = {"someSymbol"};
//     PushRulesToGrammar(grammar, "someSymbol", ruleA, 1);

//     char *ruleB[1] = {"someOtherSymbol"};
//     PushRulesToGrammar(grammar, "someOtherSymbol", ruleB, 1);

//     // int i;
//     // for (i = 0; i < testStringsCount; i++)
//     // {
//     //     AddSymbolToGrammar(grammar, testStrings[i]);
//     // }

//     FreeGrammar(grammar);

//     return 0;
// }

int testGrammar()
{
    Grammar *grammar = CreateGrammar();
    _assert(grammar);
    FreeGrammar(grammar);

    return 0;
}

int testSymbol()
{
    // Manualy parsed rules
    char *testString = "someSymbol and someOtherSymbol";

    Text text = {.string = testString, .start = 1, .end = 14};
    Text someSymbolText = {.string = testString, .start = 0, .end = 13};
    Text someOtherSymbolText = {.string = testString, .start = 15, .end = 29};

    Token textToken = {.data = (void *)&text, .type = TEXT};
    Token someSymbolTextToken = {.data = (void *)&text, .type = TEXT};
    Token someOtherSymbolTextToken = {.data = (void *)&text, .type = TEXT};

    Rule someSymbolRule = {.tokens = &someSymbolTextToken, .count = 1};
    Rule someOtherSymbolRule = {.tokens = &someOtherSymbolTextToken, .count = 1};

    Token someSymbolRuleToken = {.data = (void *)&someSymbolRule, .type = RULE};
    Token someOtherSymbolRuleToken = {.data = (void *)&someOtherSymbolRule, .type = RULE};
    
    Rule originRule = {.tokens = (Token []){someSymbolRuleToken, textToken, someOtherSymbolRuleToken}, .count = 3};

    Grammar *grammar = CreateGrammar();
    grammar->origin = &originRule;

    char *flattened = FlattenGrammar(grammar);
    _assert(!strcmp("someSymbol and someOtherSymbol", flattened));
    free(flattened);

    // // Grammar *grammar = CreateGrammar();
    // // char *flattened = FlattenGrammar(grammar);
    // // _assert(!strcmp("someSymbol and someOtherSymbol", flattened));

    FreeGrammar(grammar);
    free(flattened);

    return 0;
}
int testGrammarFromStream()
{
    char *filepath = "";
    Grammar *grammar = CreateGrammarFromStream(filepath);
    char *flattened = FlattenGrammar(grammar);
    printf("%s\n", flattened);

    return 0;
}

int all_tests()
{
    _verify(testSymbol);
    // _verify(testGrammarFromStream);

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