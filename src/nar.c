/*Narrative Engine structure*/

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
 
struct Component NewComponent(char *id, char *values[]){
    struct Component c;
    
    return c;
}