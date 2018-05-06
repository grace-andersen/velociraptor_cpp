#include "swarm.h"



//calls functions to form turn 
void turn( Creature monster, int quantity_monsters )
{
	//first attack 

	//if the first attack has advantage
	if( monster.first_attack.advantage() )
	{

	}

	//second attack
	if( monster.second_attack.get_message() == "null" )
	{

	}

	//third attack
	if( monster.third_attack.get_message() == "null" )
	{

	}

}



int attack_advantage( )
{
	Dice d20(20);
	int roll = d20.roll_n_k1( 1, 'h' );
	return roll;
}


int attack_normal()
{
	Dice d20(20);
	int roll = d20.roll();
	return roll;
}


int attack_disadvantage()
{
	Dice d20(20);
	int roll = d20.roll_n_k1( 1, 'l');
	return roll;
}