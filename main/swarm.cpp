#include "swarm.h"




//Attack Functions
Attack::Attack( bool get_advantage, bool get_disadvantage, int get_dmg_dice_num, 
	int get_dmg_dice_sides, int get_input_dmg_mod, int get_input_attack_mod, string get_message  )
{
	has_advantage    = get_advantage;
	has_disadvantage = get_disadvantage;
	dmg_dice_num     = get_dmg_dice_num;
	dmg_dice_sides   = get_dmg_dice_sides;
	dmg_mod          = get_input_dmg_mod;
	attack_mod       = get_input_attack_mod;
	message          = get_message;
	return;
}

Attack::~Attack()
{
	return;
}

Attack::Attack( Attack &the_attack )
{
	has_advantage    = the_attack.has_advantage;
	has_disadvantage = the_attack.has_disadvantage;
	dmg_dice_num     = the_attack.dmg_dice_num;
	dmg_dice_sides   = the_attack.dmg_dice_sides;
	dmg_mod          = the_attack.dmg_mod;
	attack_mod       = the_attack.attack_mod;
	message          = the_attack.message;
	return;
}



void Attack::set_advantage()
{
	has_advantage = true;
	return;
}



void Attack::set_disadvantage()
{
	has_disadvantage = true;
	return;
}



void Attack::set_number_dice( int num_dice )
{
	dmg_dice_num = num_dice;
	return;
}



void Attack::set_dice_sides( int dice_sides )
{
	dmg_dice_sides = dice_sides;
	return;
}



void Attack::set_dmg_mod( int mod )
{
	dmg_mod = mod;
	return;
}



void Attack::set_attack_mod( int mod )
{
	attack_mod = mod;
	return;
}



void Attack::get_stats( ofstream out )
{
	if( (has_advantage & has_advantage) | !has_advantage | !has_disadvantage )
		out << "The creature does not have advantage or disadvantage" << endl;
	else if( has_advantage )
		out << "The creature has advantage" << endl;
	else if( has_disadvantage )
		out << "The creature has disadvantage" << endl;

	out << "The attack modifier is +" << attack_mod << endl;
	out << "The damage is " << dmg_dice_num << "d" << dmg_dice_sides << "+" << dmg_mod << endl;
	out <<  message << endl;

	return;
}



bool Attack::advantage()
{
	return has_advantage;
}
bool Attack::disadvantage()
{
	return has_disadvantage;
}
int Attack::number_dice()
{
	return dmg_dice_num;
}
int Attack::dice_sides()
{
	return dmg_dice_sides;
}
int Attack::get_dmg_mod()
{
	return dmg_mod;
}
int Attack::get_attack_mod()
{
	return attack_mod;
}

Attack &Attack::operator=( const Attack &the_attack )
{

	//set all of the variables equal
	this->has_advantage    = the_attack.has_advantage;
	this->has_disadvantage = the_attack.has_disadvantage;
	this->dmg_dice_num     = the_attack.dmg_dice_num;
	this->dmg_dice_sides   = the_attack.dmg_dice_sides;
	this->dmg_mod          = the_attack.dmg_mod;
	this->attack_mod       = the_attack.attack_mod;
	this->message          = the_attack.message;

	return *this;
}


//CREATURE CLASS FUNCTIONS
Creature::Creature( Attack in_first_attack, Attack in_second_attack, Attack in_third_attack)
{
	first_attack = in_first_attack;
	second_attack = in_second_attack;
	third_attack = in_third_attack;
	return;
}



//destructor
Creature::~Creature()
{
	return;
}



int Creature::optimal_turn( Attack first_attack, Attack second_attack, Attack third_attack )
{
	return 0;
}



//OTHER
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



char Creature::is_hit( int ac, Attack the_attack )
{
	Dice d20( 20 );
	int the_roll = d20.roll();

	if( the_roll == 20 )
	{
		return 'c';
	}

	//if the attack is greater than the armor class
	if( ( the_roll + the_attack.get_attack_mod() ) > ac )
	{
		return 'h';
	}

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

