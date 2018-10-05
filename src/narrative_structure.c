#include "narrative_structure.h"

typedef struct Component component;
typedef struct State state;
typedef struct Action action;

component NewInstance(component c)
{
    component co = {
        .id="test",
        .values="alive|dead",
        .current=0,
    };
    return co;
}
