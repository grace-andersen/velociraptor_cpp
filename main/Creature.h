#include "Attack.h"

class Creature
{


	public: 
		//constructor
		Creature( string the_name, Attack first_attack, Attack second_attack, 
			Attack third_attack);
		//destructor
		~Creature();

		
		int hit_damage( Attack attack_type );
		int crit_damage( Attack attack_type );
		char is_hit( int ac, Attack the_attack );
		void output_condition( Attack attack, int hits );

		//contains all information for attacks
		virtual int optimal_turn( Attack first_attack, Attack second_attack, 
			Attack third_attack );

	private: 
		string name;
		Attack first_attack;
		Attack second_attack;
		Attack third_attack;
	
};