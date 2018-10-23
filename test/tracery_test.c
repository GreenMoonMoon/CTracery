#include "unittest.h"
#include "tracery.h"

int TestGeneralParsing()
{
    struct TraceryParser *tracery = NewParser();
    (*tracery).Parse("");
    (*tracery).Parse("fooo");
    (*tracery).Parse("####");
    (*tracery).Parse("#[]#[]##");
    (*tracery).Parse("#someSymbol# and #someOtherSymbol#");
    (*tracery).Parse("#someOtherSymbol.cap.pluralize#");
    (*tracery).Parse("#[#do some things#]symbol.mod[someotherthings[and a function]]#");
    (*tracery).Parse("#[fxn][fxn][fxn[subfxn]]symbol[[fxn]]#");
    (*tracery).Parse("#[fxn][#fxn#][fxn[#subfxn#]]symbol[[fxn]]#");
    (*tracery).Parse("#hero# ate some #color# #animal.s#");

    // bad
    (*tracery).Parse("#someSymbol# and #someOtherSymbol");
    (*tracery).Parse("#[fxn][fxn][fxn[subfxn]]symbol[fxn]]#");

    // good
    (*tracery).ParseTag("[action]symbol.mod1.mod2[postAction]");

    // bad
    (*tracery).ParseTag("stuff[action]symbol.mod1.mod2[postAction]");
    (*tracery).ParseTag("[action]symbol.mod1.mod2[postAction]stuff");

    (*tracery).Parse("#[#setPronouns#][#setOccupation#][hero:#name#]story#");
    (*tracery).Parse("#hero# ate some #color# #animal.s#");
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