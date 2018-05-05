#include "Dice.h"

/*
Todo: 
menu
creature class
attack method
crit damage function
normal damage function
hit calculation function
*/



class Attack 
{

	public:
		Attack( bool get_advantage = false, bool get_disadvantage = false, 
			int get_dmg_dice_num = 1, int get_dmg_dice_sides = 6, int get_input_dmg_mod = 4,
			int get_input_attack_mod = 2, string get_message = ""  );		
		~Attack();
		Attack( Attack &the_attack );
		//functions to set variables
		void set_advantage();
		void set_disadvantage();
		void set_number_dice( int num_dice );
		void set_dice_sides( int dice_sides );
		void set_dmg_mod( int mod );
		void set_attack_mod( int mod );

		//troubleshooting and manual stat use
		void get_stats( ofstream out );

		//functions to get variables
		bool advantage();
		bool disadvantage();
		int number_dice( int num_dice );
		int dice_sides( int dice_sides );
		int get_dmg_mod( int mod );
		int get_attack_mod( int mod );

		//overload some ops
		Attack &operator=( const Attack &the_attack );



	private:
		bool has_advantage;
		bool has_disadvantage;
		int dmg_dice_num;
		int dmg_dice_sides;
		int dmg_mod;
		int attack_mod;
		string message;

};





class Creature
{


	public: 
		//constructor
		Creature( Attack first_attack, Attack second_attack, Attack third_attack);
		//destructor
		~Creature();

		
		int hit_damage( Attack attack_type );
		int crit_damage( Attack attack_type );
		bool is_hit( int ac, int roll, int damage_mod, bool crit );
		void output_condition( Attack attack, int hits );

		//contains all information for attacks
		int optimal_turn( Attack first_attack, Attack second_attack, Attack third_attack );

	private: 
		Attack first_attack;
		Attack second_attack;
		Attack third_attack;
	
};


//returns ac and creature and advantage


//calls functions to form turn 
void turn( Creature monster, int quantity_monsters );

