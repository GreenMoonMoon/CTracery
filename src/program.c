#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct dynarray
{
    char **array;
    int count;
    int capacity;
} dynarray;

dynarray *NewDynarray(int capacity)
{
    dynarray *d = malloc(sizeof(dynarray));
    (*d).array = malloc(capacity * sizeof(char *));
    (*d).count = 0;
    (*d).capacity = capacity;

    return d;
}

void AppendDynarray(dynarray *d, char *value)
{
    if (d->count == d->capacity)
    {
        d->capacity *= 2;
        d->array = realloc(d->array, d->capacity * sizeof(char *));
    }
    d->array[d->count++] = value;
}

void FreeDynarray(dynarray *d)
{
    free((*d).array);
    free(d);
}

int main(void)
{
    char stringA[] = "tests this string ";
    char stringB[] = "with some functions";
    char *stringC;

    size_t size =  strlen(stringA) + strlen(stringB);
    stringC = calloc(size, sizeof(char));
    strcpy(stringC, stringA);
    strcat(stringC, stringB);

    printf("%s\n", stringC);
    int position = strchr(stringC, 'g') - &stringC[0];
    printf("First occurence of 'g' at %d\n", position);

    free(stringC);
    return 0;
}
