#include "narrative_structure.h"

typedef struct Component component;
typedef struct State state;
typedef struct Action action;

component NewInstance(component c)
{
    component co = {};
    return co;
}
