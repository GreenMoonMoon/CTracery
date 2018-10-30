// Port of Tracery
// Original author: Kate Compton
#ifndef __TRACERY__
#define __TRACERY__

struct Action
{
    int selected;
};

struct Symbol
{
    int selected;
};

struct Modifier
{
    int selected;
};

typedef struct Grammar
{
    // Container for symbol and modifiers.
    int selected;
    void (*Destroy)();
} Grammar;

typedef struct TraceryOBJ
{
    struct Action *preActions;
    struct Action *postActions;
    struct Symbol *symbols;
    struct Modifier *mods;
} TraceryOBJ;

typedef struct Tracery
{
    //General struct used to access Tracery specific functions.
    //TODO: check if such container is actually usefull, it might be better
    //to leave all the function in the open with meaningfull name to avoid
    //collision.
    void (*Parse)(char *string, int stringSize);
    void (*ParseTag)(char *string, int stringSize);
    void (*Destroy)();
} Tracery;

Tracery *NewTracery();
static void DestroyTraceryFunc(Tracery *tracery);
void FreeTracery(Tracery *tracery);

void ParseFunc(char *string, int stringSize);
void ParseTagFunc(char *string, int stringSize);

Grammar *NewGrammar();
static void DestroyGrammarFunc(Grammar *grammar);
void FreeGrammar(Grammar *grammar);

#endif