#include "Creature.h"


/******************************************************************
The constructor just defines the attacks of the creature
******************************************************************/
Creature::Creature( string the_name, Attack in_first_attack, 
	Attack in_second_attack, Attack in_third_attack)
{
	name = the_name;
	first_attack = in_first_attack;
	second_attack = in_second_attack;
	third_attack = in_third_attack;
	return;
}



/******************************************************************
The destructor doesn't need to do anything right now
******************************************************************/
Creature::~Creature()
{
	return;
}



int Creature::optimal_turn( Attack first_attack, Attack second_attack, Attack third_attack )
{
	return 0;
}



/******************************************************************
This function will calculate damage from a normal hit, and return
that damage.
******************************************************************/
int Creature::hit_damage( Attack attack_type )
{
	//create dice 
	Dice damage_dice( attack_type.dice_sides() );
	int damage;

	//roll number_dice and sum them
	for( int i = 0; i < attack_type.number_dice(); i++ )
	{
		damage += damage_dice.roll();
	}
	damage += attack_type.get_dmg_mod();

	return damage;
}


/******************************************************************
This function will calculate crit damage for an attack passed in, 
and return the damage
******************************************************************/
int Creature::crit_damage( Attack attack_type )
{
	//create dice 
	Dice damage_dice( attack_type.dice_sides() );

	//holds the damage dealt
	int damage;

	//roll number_dice and sum them
	for( int i = 0; i < attack_type.number_dice(); i++ )
	{
		damage += damage_dice.roll() + damage_dice.roll();
	}
	damage += attack_type.get_dmg_mod();

	return damage;
}


/******************************************************************
This function will determine if a creature hits. The function
returns 'c' if the hit is a crit, 'h' if it hits, and 'm' if
the attack misses
******************************************************************/
char Creature::is_hit( int ac, Attack the_attack )
{
	Dice d20( 20 );
	int the_roll = d20.roll();

	//if the attack is a crit
	if( the_roll == 20 )
	{
		return 'c';
	}

	//if the attack is greater than the armor class
	if( ( the_roll + the_attack.get_attack_mod() ) > ac )
	{
		return 'h';
	}

	//else the attack missed
	return 'm';
}


void Creature::output_condition( Attack attack, int hits )
{

	return;
}

void turn(Creature monster, int quantity_monsters )
{

	return;
}

