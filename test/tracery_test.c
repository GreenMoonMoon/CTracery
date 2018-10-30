#include <stdio.h>

#include "unittest.h"
#include "../src/tracery.h"

int TestParse()
{
    Tracery *tracery = NewTracery();
    int sectionCount = NULL;

    char *testInvalidRule1 = "";
    char **result = tracery->Parse(testInvalidRule1, &sectionCount);
    _assertEqual(sectionCount, 0);

    char *testInvalidRule2 = "fooo";
    result = tracery->Parse(testInvalidRule2, &sectionCount);
    _assertEqual(sectionCount, 0);

    // char *testInvalidRule3 = "####";
    // result = tracery->Parse(testInvalidRule3, &sectionCount);
    // _assertEqual(result, NULL);

    // result = tracery->Parse("#[]#[]##", &sectionCount);
    // _assertEqual(result, NULL);

    char *testValideRule1 = "#someSymbol# and #someOtherSymbol#";
    result = tracery->Parse(testValideRule1, &sectionCount);
    _assertEqual(sectionCount, 3);
    _assertEqual((char*)&result[0], &testValideRule1[0]);
    _assertEqual((char*)&result[1], &testValideRule1[0] + 12);
    _assertEqual((char*)&result[2], &testValideRule1[0] + 17);

    // result = tracery->Parse("#someOtherSymbol.cap.pluralize#", 31);
    // _assertEqual(result, 0);

    // result = tracery->Parse("#[#do some things#]symbol.mod[someotherthings[and a function]]#", 63);
    // _assertEqual(result, 0);

    // result = tracery->Parse("#[fxn][fxn][fxn[subfxn]]symbol[[fxn]]#", 38);
    // _assertEqual(result, 0);

    // result = tracery->Parse("#[fxn][#fxn#][fxn[#subfxn#]]symbol[[fxn]]#", 42);
    // _assertEqual(result, 0);

    // result = tracery->Parse("#hero# ate some #color# #animal.s#", 34);
    // _assertEqual(result, 0);

    // result = tracery->Parse("#[#setPronouns#][#setOccupation#][hero:#name#]story#", 52);
    // _assertEqual(result, 0);

    // result = tracery->Parse("#hero# ate some #color# #animal.s#", 34);
    // _assertEqual(result, 0);


    // // bad
    // result = tracery->Parse("#someSymbol# and #someOtherSymbol", 33);
    // _assertEqual(!result, 0);

    // result = tracery->Parse("#[fxn][fxn][fxn[subfxn]]symbol[fxn]]#", 37);
    // _assertEqual(!result, 0);

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