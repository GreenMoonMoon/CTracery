#include "unittest.h"
#include "../src/grammar_parser.h"

int TestGeneralParsing()
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
