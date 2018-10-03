# General Notes
The narrative engine is composed of 2(*3?*) distinc parts. The data structure, the generator and the interrest monitoring system.
## Narrative composition
The building blocks of strories are actors, their actions, their motivations, events, locations, etc. The chalenge is to define them for a computer. The current goal is to build a video game story line for the player to enact or affect. The later is a bit easier, since the player can unknowingly become the writer. While building full compeling stories proceduraly can be both expensive and extremely tricky, it isn't necessary to let the computer build everything. The simple approche would be to simply automate everything that can be automated and leave the rest for someone to write.

Stories can generaly be decomposed in multiple arc that follow similar pattern. With a handful of these pattern we can build compelling narrative easily. The second element are the actors and their motivation. Character psyche can be hard to write, harder still to generate with a computer but it can be helped by archetype templates. Motivations and goals can be picked up from enviroments, events or player actions. Archetypes can also help define behavior and descisions process of actors. Events caused by actors or the environments are what makes the narrative move foward.
The player generaly reacts to these stimuli and makes its own descisions in order to acheive its goals, whether he or she sets them or not.
## Data Structure
Hold all narrative relevant data. Can be manipulated and used to actualyze the story within the game. This structure does not have any logic, it is mainly a tool to represent narrative structure within the game.
One key feature of this data structure will be to handle a growing list of componenet and their possible status.
### Component
This is the basic building part of the structure.
#### Declaration
To declare a new component, first indicate which component the new one inherit from, `Component` is the default if nothing is specified. Then indicate the name of this new component followed by square bracket containing possible status, the bracket can be left empty.

`Component {type} [<{status| ...}|>]`

To declare an instance of a component, first indicate the type of component followed byt the instance name and the desired status. The status is mandatory therefore it is good practice to setup default statuses when declaring component types.

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
## Generator
Generates all variables for the narrative engine. Uses various heuristic to output the most relevant variables to the current narrative. Generate the narrative structure by completing templates. Uses the IMS to make the narrative more compeling to the player.
## Interrest monitoring system
Gather all relevant data from the player playstyle. Such as which NPCs is spoken to the more often, which area is more explored, etc. These informations can be used to asing weight to various components. The Generator will then be able to use it to further personalyse the player experience.
# TODOs
- [x] Create the basic language for declaring [compoents](#component).
- [ ] Create a basic parser for reading and writing [component](#component) declarations.
- [ ] Create the structure for [States](#states) and [Actions](#actions).
- [ ] Refactor the paragraph about [narrative composition](#narrative-composition)
# Table of contents
- [General Notes](#general-notes)
    - [Narrative composition](#narrative-composition)
    - [Data Structure](#data-structure)
        - [Component](#component)
            - [Declaration](#declaration)
        - [States](#states)
        - [Actions](#actions)
    - [Generator](#generator)
    - [Interrest monitoring system](#interrest-monitoring-system)
- [TODOs](#todos)
- [Table of contents](#table-of-contents)