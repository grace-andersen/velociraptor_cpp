#include "swarm.h"



//calls functions to form turn 
void turn( Creature monster, int quantity_monsters, int ac )
{
	int damage = 0;
	int is_hit = 0;
	//first attack 

	for( int i = 0; i < quantity_monsters; i++ )
	{
		//if the first attack has advantage
		if( monster.first_attack.advantage() )
		{
			is_hit =  monster.is_hit_advantage( ac, monster.first_attack );
			if( is_hit == hit )
				damage += monster.hit_damage( monster.first_attack );
			else if( is_hit == crit )
				damage += monster.crit_damage( monster.first_attack );
		}
		else
		{
			is_hit =  monster.is_hit( ac, monster.first_attack );
			if( is_hit == hit )
				damage += monster.hit_damage( monster.first_attack );
			else if( is_hit == crit )
				damage += monster.crit_damage( monster.first_attack );
			
		}

		//second attack
		if( monster.second_attack.get_message() == "null" )
		{
			if( monster.second_attack.advantage() )
			{
				is_hit =  monster.is_hit_advantage( ac, monster.second_attack );
				if( is_hit == hit )
					damage += monster.hit_damage( monster.second_attack );
				else if( is_hit == crit )
					damage += monster.crit_damage( monster.second_attack );
			}
			else
			{
				is_hit =  monster.is_hit( ac, monster.second_attack );
				if( is_hit == hit )
					damage += monster.hit_damage( monster.second_attack );
				else if( is_hit == crit )
					damage += monster.crit_damage( monster.second_attack );
			
			}
		}

		//third attack
		if( monster.third_attack.get_message() == "null" )
		{
	
		}
	}

}



int roll_advantage()
{
	Dice d20(20);
	//h means keep the high roll
	int roll = d20.roll_n_k1( 1, 'h' );
	return roll;
}


int roll_normal()
{
	Dice d20(20);
	int roll = d20.roll();
	return roll;
}


int roll_disadvantage()
{
	Dice d20(20);
	//l means keep the low roll
	int roll = d20.roll_n_k1( 1, 'l');
	return roll;
}


