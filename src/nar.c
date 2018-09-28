/*Narrative Engine structure*/

struct Component
{
    char *id;
    char *values;
    int current;
};

struct State
{
    /* data */
};
 
struct Action
{
    /* data */
};
 
struct Component NewComponent(char *id, char *values[]){
    struct Component c;
    
    return c;
}