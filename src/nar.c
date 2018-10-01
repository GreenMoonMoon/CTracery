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
 
struct Component NewComponent(char *id, int count, ...){
    va_list ap;
    va_start()
    * values = malloc(sizeof())
    Component c = (Component){.id = "Being", .values = [](char*)[]{"alive", "dead"}, .current = 0};
    
    return c;
}