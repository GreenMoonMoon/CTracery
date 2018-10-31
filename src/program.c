#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void changeValue(int *p);

int main(void)
{
    int s = 3;
    printf("s: %d\n", s);
    changeValue(&s);
    printf("s: %d\n", s);
    return 0;
}

void changeValue(int *p)
{
    *p = 10;
}
