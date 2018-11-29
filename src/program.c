#include <stdlib.h>
#include <stdio.h>
// #include <string.h>

#include <wchar.h>

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

static int compareKey(const char *key1, const char *key2)
{
    int i = 0;
    while (key1[i] == key2[i])
    {
        if (key1[i] == '\0')
            return 1;
        i++;
    }
    return 0;
}

int main(void)
{
    char *key1 = "test";
    char *key2 = "test";
    char *key3 = "tezt";

    if (compareKey(key1, key2))
        printf("First is true!\n");
    else
        printf("First failed!!!!");
    if (!compareKey(key1, key3))
        printf("Second is false!\n");
    else
        printf("Second failed!!!!");

    return 0;
}
