/*Narrative Engine structure*/
#include <stdlib.h>
#include <stdarg.h>

typedef struct Component
{
    char id;
    char **values;
    int current;
} Component;

// struct State
// {
//     struct Component *components;
//     struct Action *actions;
// } State;

// struct Action
// {
//     struct Component component;
//     int value;
// } Action;

Component *NewInstance(Component c)
{
    return &c;
}