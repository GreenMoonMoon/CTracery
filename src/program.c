#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{   
    char *testString = "fooo";
    
    printf("testString: %s\n", testString);
    printf("testString[0]: %c\n", testString[0]);
    printf("&testString[0]: %p\n", &testString[0]);
    printf("sizeof(testString): %d\n", strlen(testString));

    char *testSubsection[1] = {testString};
    printf("testSubsection[0]: %s\n", testSubsection[0]);
    printf("testSubsection[0][0]: %c\n", testSubsection[0][0]);
    printf("&testSubsection[0][0]: %p\n", &testSubsection[0][0]);

    return 0;
}