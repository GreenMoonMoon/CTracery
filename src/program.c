#include <stdlib.h>
#include <stdio.h>

typedef struct Destroyable
{
    void (*Destroy)();
} Destroyable;

typedef struct A
{
    int *valueA;
} A;

typedef struct B
{
    int *valueB;
} B;

int main(void)
{
    A a = {.valueA = 0};
    printf("%d\n", (int)a.valueA);
    printf("%d\n", (int)&(a.valueA));

    return 0;
}