#ifndef NARRATIVE_ENGINE
#define NARRATIVE_ENGINE

#include <stdlib.h>
#include <stdarg.h>

struct Component
{
    char *id;
    char *values;
    int current;
};

struct State
{
    struct Component *components;
    struct Action *actions;
};

struct Action
{
    struct Component component;
    int value;
};

struct Component NewInstance(struct Component c);

#endif