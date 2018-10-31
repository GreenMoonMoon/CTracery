#include <stdio.h>

#include "unittest.h"
#include "../src/tracery.h"

// char **testStrings = {
//     "",
//     "fooo",
//     "#someSymbol# and #someOtherSymbol#",
//     "####",
//     "#[]#[]##",
//     "#someOtherSymbol.cap.pluralize#",
//     "#[#do some things#]symbol.mod[someotherthings[and a function]]#",
//     "#[fxn][fxn][fxn[subfxn]]symbol[[fxn]]#",
//     "#[fxn][#fxn#][fxn[#subfxn#]]symbol[[fxn]]#",
//     "#hero# ate some #color# #animal.s#",
//     "#[#setPronouns#][#setOccupation#][hero:#name#]story#",
//     "#hero# ate some #color# #animal.s#",
//     "#someSymbol# and #someOtherSymbol",
//     "#[fxn][fxn][fxn[subfxn]]symbol[fxn]]#"};
// char **testString = {
//     "[action]symbol.mod1.mod2[postAction]",
//     "stuff[action]symbol.mod1.mod2[postAction]",
//     "[action]symbol.mod1.mod2[postAction]stuff"};

int TestGrammar()
{
    Grammar *grammar = CreateGrammar();

    FreeGrammar(grammar);

    return 0;
}

int TestTrace()
{
    Grammar *grammar = CreateGrammar();
    //create rules ...
    Trace *trace = CreateTrace(grammar);
    ExpandTrace(trace);
    FlattenTrace(trace);

    FreeGrammar(grammar);

    return 0;
}

int all_tests()
{
    // _verify(TestParse);
    // _verify(TestParseSymbol);
    _verify(TestGrammar);
    _verify(TestTrace);

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