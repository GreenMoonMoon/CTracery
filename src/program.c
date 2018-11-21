#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define _is_flattened(symbol)     \
    do                            \
    {                             \
        return (!(symbol->count)); \
    } while (0)

typedef struct Symbol
{
    int count;
} Symbol;

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
    Symbol symA = {.count = 3};
    Symbol symB = {.count = 0};

    printf(_is_flattened(&symA) ? "True\n" : "False\n");
    printf(_is_flattened(&symB) ? "True\n" : "False\n");

    // char *text = "this is a phrase with 7 elements";
    // dynarray *d = NewDynarray(5);

    // AppendDynarray(d, &text[0]);
    // AppendDynarray(d, &text[5]);
    // AppendDynarray(d, &text[8]);
    // AppendDynarray(d, &text[10]);
    // AppendDynarray(d, &text[17]);
    // AppendDynarray(d, &text[22]);
    // AppendDynarray(d, &text[24]);

    // printf("%c\n", *d->array[0]);
    // printf("%c\n", *d->array[1]);
    // printf("%c\n", *d->array[2]);
    // printf("%c\n", *d->array[3]);
    // printf("%c\n", *d->array[4]);
    // printf("%c\n", *d->array[5]);
    // printf("%c\n", *d->array[6]);

    // FreeDynarray(d);
    return 0;
}
