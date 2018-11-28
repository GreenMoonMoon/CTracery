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
    char *testRule = "origin:[\"origin\"]";
    // char stringB[] = "with some functions";
    // char *stringC;

    // size_t size =  strlen(stringA) + strlen(stringB);
    // stringC = calloc(size, sizeof(char));
    // strcpy(stringC, stringA);
    // strcat(stringC, stringB);

    // printf("%s\n", stringC);
    // int position = strchr(stringC, 'g') - &stringC[0];
    // printf("First occurence of 'g' at %d\n", position);

    // free(stringC);

    // char *t;
    // t = strtok(stringA, " ");
    // while(t != NULL)
    // {
    //     printf("%s\n", t);
    //     t = strtok(NULL, " ");
    // }

    char *t;
    size_t span;
    
    span = strspn(testRule, ':');
    printf("%s\n", t);
    
    while(t != NULL)
    {
        printf("%s\n", t);
        t = strtok(NULL, "\"[]");
    }

    return 0;
}
