#include "Attack.h"

enum hit{ miss, hit, crit };

class Creature
{


	public: 
		//constructor
		Creature( string the_name, Attack first_attack, Attack second_attack, 
			Attack third_attack );
		//destructor
		~Creature();


		
		int hit_damage( Attack attack_type );
		int crit_damage( Attack attack_type );
		char is_hit( int ac, Attack the_attack );
		char is_hit_advantage( int ac, Attack the_attack );
		char is_hit_disadvantage( int ac, Attack the_attack );
		void output_condition( Attack attack, int hits );
		string name;
		Attack first_attack;
		Attack second_attack;
		Attack third_attack;

	private: 

	
};