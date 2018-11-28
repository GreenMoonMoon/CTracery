#include <stdio.h>
#include <string.h>

#include "unittest.h"
#include "../src/tracery.h"

int testGrammar()
{
    Grammar *grammar = CreateGrammar();
    _assert(grammar);
    FreeGrammar(grammar);

    return 0;
}

int testFlattenSymbol()
{
    // Manualy parsed rules
    char *testString = "someSymbol and someOtherSymbol";

    Text text = {.start = &testString[10], .length = 5};
    Text someSymbolText = {.start = &testString[0], .length = 10};
    Text someOtherSymbolText = {.start = &testString[15], .length = 15};

    Token textToken = {.data = (void *)&text, .type = TEXT};
    Token someSymbolTextToken = {.data = (void *)&someSymbolText, .type = TEXT};
    Token someOtherSymbolTextToken = {.data = (void *)&someOtherSymbolText, .type = TEXT};

    Rule someSymbolRule = {.tokens = &someSymbolTextToken, .count = 1};
    Rule someOtherSymbolRule = {.tokens = &someOtherSymbolTextToken, .count = 1};

    Token someSymbolRuleToken = {.data = (void *)&someSymbolRule, .type = RULE};
    Token someOtherSymbolRuleToken = {.data = (void *)&someOtherSymbolRule, .type = RULE};

    // This is essentially an expanded Trace.
    Rule originRule = {.tokens = (Token[]){someSymbolRuleToken, textToken, someOtherSymbolRuleToken}, .count = 3};

    Grammar *grammar = CreateGrammar();
    grammar->origin = &originRule;

    char *flattened = FlattenRule(grammar->origin);

    _assert(!strcmp("someSymbol and someOtherSymbol", flattened));

    free(flattened);
    FreeGrammar(grammar);

    return 0;
}

int testExpandSymbol()
{
    // Manualy parsed rules
    char *testString = "someSymbol and someOtherSymbol";

    Text text = {.start = &testString[10], .length = 5};
    Text someSymbolText = {.start = &testString[0], .length = 10};
    Text someOtherSymbolText = {.start = &testString[15], .length = 15};

    Token textToken = {.data = (void *)&text, .type = TEXT};
    Token someSymbolTextToken = {.data = (void *)&someSymbolText, .type = TEXT};
    Token someOtherSymbolTextToken = {.data = (void *)&someOtherSymbolText, .type = TEXT};

    Rule someSymbolRule = {.tokens = &someSymbolTextToken, .count = 1};
    Rule someOtherSymbolRule = {.tokens = &someOtherSymbolTextToken, .count = 1};

    Token someSymbolRuleToken = {.data = (void *)&someSymbolRule, .type = RULE};
    Token someOtherSymbolRuleToken = {.data = (void *)&someOtherSymbolRule, .type = RULE};

    // This is essentially an expanded Trace.
    Rule originRule = {.tokens = (Token[]){someSymbolRuleToken, textToken, someOtherSymbolRuleToken}, .count = 3};

    Grammar *grammar = CreateGrammar();
    grammar->origin = &originRule;

    char *flattened = FlattenRule(grammar->origin);
    printf("%s\n", flattened);

    _assert(!strcmp(testString, flattened));
    free(flattened);

    FreeGrammar(grammar);

    return 0;
}

int testScanRule()
{
    Grammar *grammar = CreateGrammar();

    char *testRule = "origin:[\"origin\"]";
    int scanned = ScanRule(grammar, testRule);

    // printf("%s\n", testRule);
    // _assert(scanned);

    // // Token *tokens = grammar->rules[0].tokens;

    // // _assert(tokens[0].type == TEXT);
    // // _assert(strcmp((char *)tokens[0].data, "origin"));

    FreeGrammar(grammar);

    return 0;
}

int testGrammarFromStream()
{
    FILE *testStream = tmpfile();
    _assert(testStream != NULL);

    char src[] = {
        "someSymbol:[\"SymbolA\", \"SymbolB\"]\n"
        "someOtherSymbol:[\"OtherSymbolA\", \"OtherSymbolB\"]\n"
        "origin:[\"#someSymbol and someOtherSymbol#\"]\0"
    };
    fputs(src, testStream);
    rewind(testStream);

    Grammar *grammar = CreateGrammarFromStream(testStream);
    _assert(grammar);
    // Grammar *grammar = CreateGrammarFromStream(testStream);

    // FreeGrammar(grammar);

    return 0;
}

int all_tests()
{
    // _verify(testFlattenSymbol);
    // _verify(testExpandSymbol);
    // _verify(testScanRule);
    _verify(testGrammarFromStream);

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