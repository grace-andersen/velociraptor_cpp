#include "Dice.h"


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
		int number_dice();
		int dice_sides();
		int get_dmg_mod();
		int get_attack_mod();
		string get_message();

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
