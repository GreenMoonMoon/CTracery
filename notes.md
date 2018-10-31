# General Notes
## Summary
The narrative engine is composed of 2(*3?*) distinc parts. The data structure, the generator and the interrest monitoring system.

The building blocks of strories are actors, their actions, their motivations, events, locations, etc. The chalenge is to define them for a computer and the current goal is to build a video game story line for the player to enact or affect. The later is a bit easier, since the player can unknowingly become the writer. While building full compeling stories proceduraly can be both expensive and extremely tricky, it isn't necessary to let the computer build everything. The simple approche would be to simply automate everything that can be automated and leave the rest for someone to write.
The *Narrative Engine* should be able to parse narrative structure files, be passed narrative objects, run basic operation on them and returns the result as narrative objects.


The templates, which will provide specific interpretation of the data
a template will be chosen by finding key elements in the context(game state)
and the data (actors, actions, motivations and such, etc.) will be applied to the template

Template can be extremely simple, small story structure that can be coupled to other template for a more complexe story structure. Most stories can be broken down in small pieces that act around and on each other
*Humor template could be desastrously hard to craft due to the shear number of humor pattern and theory out there.*

Templates are authored, but can be mixed if they don't conflict with each other.
These templates are bound by the context, if the context does not permit a template, then this template will not be chosen. This enable control over the story structure and developpment. Templates are always chosen based on current context, they do not affect the context therefore the game needs to generate a bunch of *leads* that could be used. The generated leads may or may not be affected by the player actions. A good idea would be to insert general leads for more authored content and specific ones based on the player interest for side content.
The game would use the template to align objects into their next states or to drive the simulation. Then depending on how frequently the game state is analysed
another temlate is applied to the current state. All previous actions are recorded, player wise or game wise as they can serve as pseudo-context or context for the next templates.
Stories can generaly be decomposed in multiple arc that follow similar pattern. With a handful of these pattern we can build compelling narrative easily. The second element are the actors and their motivation. Character psyche can be hard to write, harder still to generate with a computer but it can be helped by archetype templates. Motivations and goals can be picked up from enviroments, events or player actions. Archetypes can also help define behavior and descisions process of actors. Events caused by actors or the environments are what makes the narrative move foward.
### The way stories are constructed
Stories are constructed as a _chain_ of action > reaction or ***events***. The chain is constructed first and then the reader, viewer or player will move down the chain and experience the events in a linear or semi-linear fashion.
In the context of a passive media such as books or movies, it makes sense. The audiences does not have any control on the story, it's a mere recollection of events. It is the same with ***Let's play*** videos. However in a video game, the player have or should have agency on his or her actions. Often this agency is left to some part of the gameplay experience while crucial event are done trought cut-scenes or scripted event, overall reducing the impact of interactivity. We can look at books or movies as tree of possibilities that have been collapsed by the author who plays the role of both the developper and the player.

Let's consider a game where the story is a collection of events that aren't linked by time. They can occure in at any moment and in any order. However these events have requirements that needs to be met in order for the event to occure.
Both the player and events can alter the world state, filling requirements for more events to occurs. NPCs quests, overarching story and bonus side-quests can be seen as stacks of template representing possible events, with requirements and effects.
As the player progress trought the game, sets in motion events and follow his or her own story.
Story can have a strictly possitive progression, where events and actions changed until they fill specific requirement and then makes the whole story progress. Or they can have negative and positive progressions, where event and the player can unset requirements, thus moving in the story has they please.

Stacked templates create complex behavior by creating event based on current world state. Story are a linear reconstruction of events that did not exists in a linear state before happening. Templates are guides, world state can be influenced or not by them.

## Basic Data Structure
Hold all narrative relevant data. Can be manipulated and used to actualyze the story within the game. This structure does not have any logic, it is mainly a tool to represent narrative structure within the game.
One key feature of this data structure will be to handle a growing list of componenet and their possible status.
### Component
This is the basic building part of the structure.
#### Declaration
To declare a new component, first indicate which component the new one inherit from, `Component` is the default if nothing is specified. Then indicate the name of this new component followed by square bracket containing possible status, the bracket can be left empty.

`Component {type} [<{status| ...}|>]`

To declare an instance of a component, first indicate the type of component followed byt the instance name and the desired status. The status is mandatory therefore it is good practice to set up default statuses when declaring component types.

`{type} {id} {status}`

The `type` and `status` are defined in advances, before declaring instances. Component can inherit from one another. For example:
```
Component Person [dead|alive]
Person Knight [chivalrous|coward]
Knight sirKnight alive
sirKnight chivalrous
```
Component can also inherit from multiple component by inserting a comma between Component types. The last declared name before the square brackets is the new component name:
```
Knight, Dragon Dragoneer []
```

This is valid, since Knight is an extention of Person. The type Component is the predefined default component type.

The `id` attribute groups component together. A component group can only contain one instance of each component. All component with the same id are considered part of the same *narrative entity*.
### States
### Actions

## Template
### narrative
The narrative template is the main narrative element.
### Archetype
Archetypes templates are used to define actors. 
## Generator
Generates all variables for the narrative engine. Uses various heuristic to output the most relevant variables to the current narrative. Generate the narrative structure by completing templates. Uses the IMS to make the narrative more compeling to the player.
## Interrest monitoring system
Gather all relevant data from the player playstyle. Such as which NPCs is spoken to the more often, which area is more explored, etc. These informations can be used MayaCmdOverrideto asing weight to various components. The Generator will then be able to use it to further personalyse the player experience.
# TODOs
- [x] Create the basic language for declaring [compoents](#component).
- [ ] Create a basic parser for reading and writing [component](#component) declarations.
- [ ] Create the structure for [States](#states) and [Actions](#actions).
- [ ] Refactor the paragraph about [narrative composition](#narrative-composition)

# General C Notes
* Always pass a pointer to a struct instead of the struct itself. This is because C always pass attribute as value. Even if the struct content isn't modified, this way we don't copy the whole struct content on the stack.
* Be carefule of the scope. When returning a pointer, make sure not to return a pointer to a local value (function argument or locally declared variable). However returning a pointer to a dynamically allocated memory is fine, be careful however to free the memory once you're done with it *(migth be best to allocate the memory first and pass a pointer to it, so it's clear who allocated the memory in the fisrt place)* .
* An array type is a special type that acts like a pointer, only new values cannot be reassinged. Unspecified size array as a parameter to a function is the same as a pointer, however it is used to emphasise how the variable will be used.
* Pointer arithmetic: Pointer can be added and subtracted from one another since they are value and continuous memory location are just integer with steps of the size of the data they hold. They are added to integer multiplied by the size of the type they point to. Therefore, to iterate on an array, you can use `for(p=array;p<&array[ARRAYSIZE]; ++p)` where `&array[ARRAYSIZE]` return the pointer value of the last element in the array.
* One way of making multi-dimentionnal array with row of different lenght is to declare one single array with all value aligned one after the other and declaring a second array of pointers with the row's lenghts as each pointer. Then accessing the first one as a multi-dimentional is done using the array of pointer but make sure you don't go over by checking the pointer value of the next row.
* Make sure to always free dynamicaly allocated memory before the corresponding pointer is overwritten otherwise this will result in a memory leek.
* Make sure to create recursive free functions for your structs, free is not recursive or intelligent. **Pointers** inside struct can stay allocated but inaccessible du to the struct pointer being freed, this results in a memory leek.
* Always initialize pointers eithers by allocating them or setting them as `NULL` (delayed allocation).
* Use enum of types and add them as a variable to struct to provide runtime type information.
* When working with string. If you want a string variable that can be rewriten, use malloc. Otherwise, it's a segmentation fault.