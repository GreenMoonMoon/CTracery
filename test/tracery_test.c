#include <stdio.h>

#include "unittest.h"
#include "../src/tracery.h"

int TestParse()
{
    Tracery *tracery = NewTracery();

    tracery->Parse("", 0);
    tracery->Parse("fooo", 4);
    tracery->Parse("####", 4);
    tracery->Parse("#[]#[]##", 8);
    tracery->Parse("#someSymbol# and #someOtherSymbol#", 34);
    tracery->Parse("#someOtherSymbol.cap.pluralize#", 31);
    tracery->Parse("#[#do some things#]symbol.mod[someotherthings[and a function]]#", 63);
    tracery->Parse("#[fxn][fxn][fxn[subfxn]]symbol[[fxn]]#", 38);
    tracery->Parse("#[fxn][#fxn#][fxn[#subfxn#]]symbol[[fxn]]#", 42);
    tracery->Parse("#hero# ate some #color# #animal.s#", 34);
    tracery->Parse("#[#setPronouns#][#setOccupation#][hero:#name#]story#", 52);
    tracery->Parse("#hero# ate some #color# #animal.s#", 34);

    // bad
    tracery->Parse("#someSymbol# and #someOtherSymbol", 33);
    tracery->Parse("#[fxn][fxn][fxn[subfxn]]symbol[fxn]]#", 37);

    FreeTracery(tracery);

    return 0;
}

int TestParseTag()
{
    Tracery *tracery = NewTracery();

    // good
    tracery->ParseTag("[action]symbol.mod1.mod2[postAction]", 36);

    // bad
    tracery->ParseTag("stuff[action]symbol.mod1.mod2[postAction]", 41);
    tracery->ParseTag("[action]symbol.mod1.mod2[postAction]stuff", 41);

    FreeTracery(tracery);

    return 0;
}

int TestGrammar()
{
    Grammar *grammar = NewGrammar();

    FreeGrammar(grammar);

    return 0;
}

int all_tests()
{
    _verify(TestParse);
    _verify(TestParseTag);
    _verify(TestGrammar);

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