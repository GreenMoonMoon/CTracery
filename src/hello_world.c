#include "hello_world.h"

int main()
{
    int a;
    scanf("%d", &a);
    int b[] = {a};
    int c[5] = {a};

    printf("array b index 1: %d\n", b[0]);
    printf("array c index 1: %d\n", c[0]);

    return 0;
}

void testMalloc(int size)
{
    int *darray = (int *)malloc(size * sizeof(int));
    if (darray == NULL)
    {
        /*Always check for allocation failure, since allocation is not garenteed*/
        printf("malloc failed");
        exit(1);
    }
    int darray_size = size * sizeof(int);
    int array[10];
    printf("size of 10 int array: %d\n", (int)sizeof(array));
    printf("supposed size of %d int array: %d\n", size, darray_size);
    printf("size of darray: %d\n", (int)sizeof(darray));
    printf("size of int: %d\n", (int)sizeof(int));

    int i;
    for (i = 0; i < size; i++)
    {
        darray[i] = i;
    }
    printf("%d\n", darray[10]);
    darray = realloc(darray, 11);
    printf("%d\n", darray[10]);
    free(darray);
}