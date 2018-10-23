#include <stdio.h>
#include <errno.h>

void arrayFunc(int arr[], int ARRSIZE);

int main(void)
{
    int myArray[5] = {5, 4, 3, 2, 1};
    int myArraySize = sizeof myArray / sizeof(int);
    arrayFunc(myArray, myArraySize);

    perror("malloc failed");
    return(ENOMEM);
}

void arrayFunc(int arr[], int ARRSIZE)
{
    int *p;
    int i;
    for (p = arr, i = 0; p < &arr[ARRSIZE]; ++p, ++i)
    {
        printf("%d element of arr: %d\n", i, *p);
    }
}