#include "hello_world.h"

int main()
{
    generateState();

    return 0;
}

void generateState()
{
    /*These variables represent a general satuts*/
    // char *dragonStatus = "alive\n";
    // char *princessStatus = "kidnapped";
    // char *knightStatus = "unaware";
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