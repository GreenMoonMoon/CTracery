// Port of Tracery
// Original author: Kate Compton
#ifndef __TRACERY__
#define __TRACERY__

struct TraceryParser
{
    //Using a struct to create a pseudo object allows for parser state such as
    //last read token.
    void (*Parse)(char *string);
    void (*ParseTag)(char *string);
};

void Parse();
struct TraceryParser *NewParser();

#endif