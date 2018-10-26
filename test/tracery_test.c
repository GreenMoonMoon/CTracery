#include <stdio.h>

#include "unittest.h"
#include "../src/tracery.h"

int TestGeneralParsing()
{
    struct TraceryParser *tracery = NewTracery();
    tracery->Parse("");
    tracery->Parse("fooo");
    tracery->Parse("####");
    tracery->Parse("#[]#[]##");
    tracery->Parse("#someSymbol# and #someOtherSymbol#");
    tracery->Parse("#someOtherSymbol.cap.pluralize#");
    tracery->Parse("#[#do some things#]symbol.mod[someotherthings[and a function]]#");
    tracery->Parse("#[fxn][fxn][fxn[subfxn]]symbol[[fxn]]#");
    tracery->Parse("#[fxn][#fxn#][fxn[#subfxn#]]symbol[[fxn]]#");
    tracery->Parse("#hero# ate some #color# #animal.s#");

    // bad
    tracery->Parse("#someSymbol# and #someOtherSymbol");
    tracery->Parse("#[fxn][fxn][fxn[subfxn]]symbol[fxn]]#");

    // good
    tracery->ParseTag("[action]symbol.mod1.mod2[postAction]");

    // bad
    tracery->ParseTag("stuff[action]symbol.mod1.mod2[postAction]");
    tracery->ParseTag("[action]symbol.mod1.mod2[postAction]stuff");

    tracery->Parse("#[#setPronouns#][#setOccupation#][hero:#name#]story#");
    tracery->Parse("#hero# ate some #color# #animal.s#");

    // struct TraceryParser *tracery = NewParser();
    // (*tracery).Parse("");
    // (*tracery).Parse("fooo");
    // (*tracery).Parse("####");
    // (*tracery).Parse("#[]#[]##");
    // (*tracery).Parse("#someSymbol# and #someOtherSymbol#");
    // (*tracery).Parse("#someOtherSymbol.cap.pluralize#");
    // (*tracery).Parse("#[#do some things#]symbol.mod[someotherthings[and a function]]#");
    // (*tracery).Parse("#[fxn][fxn][fxn[subfxn]]symbol[[fxn]]#");
    // (*tracery).Parse("#[fxn][#fxn#][fxn[#subfxn#]]symbol[[fxn]]#");
    // (*tracery).Parse("#hero# ate some #color# #animal.s#");

    // // bad
    // (*tracery).Parse("#someSymbol# and #someOtherSymbol");
    // (*tracery).Parse("#[fxn][fxn][fxn[subfxn]]symbol[fxn]]#");

    // // good
    // (*tracery).ParseTag("[action]symbol.mod1.mod2[postAction]");

    // // bad
    // (*tracery).ParseTag("stuff[action]symbol.mod1.mod2[postAction]");
    // (*tracery).ParseTag("[action]symbol.mod1.mod2[postAction]stuff");

    // (*tracery).Parse("#[#setPronouns#][#setOccupation#][hero:#name#]story#");
    // (*tracery).Parse("#hero# ate some #color# #animal.s#");

    // Parse("");
    // Parse("fooo");
    // Parse("####");
    // Parse("#[]#[]##");
    // Parse("#someSymbol# and #someOtherSymbol#");
    // Parse("#someOtherSymbol.cap.pluralize#");
    // Parse("#[#do some things#]symbol.mod[someotherthings[and a function]]#");
    // Parse("#[fxn][fxn][fxn[subfxn]]symbol[[fxn]]#");
    // Parse("#[fxn][#fxn#][fxn[#subfxn#]]symbol[[fxn]]#");
    // Parse("#hero# ate some #color# #animal.s#");

    // // bad
    // Parse("#someSymbol# and #someOtherSymbol");
    // Parse("#[fxn][fxn][fxn[subfxn]]symbol[fxn]]#");

    // // good
    // ParseTag("[action]symbol.mod1.mod2[postAction]");

    // // bad(.text+0x20): undefined reference to `main'
    // ParseTag("stuff[action]symbol.mod1.mod2[postAction]");
    // ParseTag("[action]symbol.mod1.mod2[postAction]stuff");

    // Parse("#[#setPronouns#][#setOccupation#][hero:#name#]story#");
    // Parse("#hero# ate some #color# #animal.s#");

    tracery->Free();

    return 0;
}

int TestGrammar()
{
    return 0;
}

int all_tests()
{
    _verify(TestGeneralParsing);

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