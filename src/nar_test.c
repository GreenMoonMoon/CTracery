#include <stdio.h>
#include "unittest.h"

int TestDeclareComponentType(){return 0;}
int TestDeclareComponentInstance(){return 0;}

int all_tests()
{
    _verify(TestDeclareComponentType);
    _verify(TestDeclareComponentInstance);
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
