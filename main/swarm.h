#include "Creature.h"

/*
Todo: 
menu
creature class
attack class
crit damage function
normal damage function
hit calculation function
*/


//calls functions to form turn 
void turn( Creature monster, int quantity_monsters, int ac );


int roll_advantage();
int roll_normal();
int roll_disadvantage();

int attack_advantage( Creature monster, int ac );