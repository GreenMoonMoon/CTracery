#include <stdlib.h>
#include <stdio.h>

// #include "tracery.h"

int *ReturnPointer();

int main(void)
{
    // Grammar *grammar = NewGrammar();
    // LoadGrammar(grammar, "../data/sci_fi.gram");

    int *t = ReturnPointer();
    printf("%d\n", (int)t);

    return 0;
}

int *ReturnPointer()
{
    int *p = (int*)malloc(sizeof(int));
    if(p == NULL){
        exit(-1);
    }
    printf("%d\n", (int)p);

    return p;
}