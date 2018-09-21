#include <stdio.h>
#include "hello_world.h"

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)

int tests_run = 0;

#define _assert(test) \
    do                \
    {                 \
        if (!(test))  \
        {             \
            FAIL();   \
            return 1; \
        }             \
    } while (0)
#define _verify(test)   \
    do                  \
    {                   \
        int r = test(); \
        tests_run++;    \
        if (r)          \
            return r;   \
    } while (0)

int test_a()
{
    _assert(25 == 25);
    return 0;
}

int all_tests()
{
    _verify(test_a);
    return 0;
}

int main(int argc, char **argv)
{
    int result = all_tests();
    if (result == 0)
        printf("PASSED\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}