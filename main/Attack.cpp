#include "Attack.h"


/******************************************************************
The constructor sets all the values and has defaults set in the 
h file
******************************************************************/
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


/******************************************************************
The destructor doesn't need to do anything.
******************************************************************/
Attack::~Attack()
{
	return;
}


/******************************************************************
Copy Constructor! it copies things 
******************************************************************/
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


/******************************************************************
Sets the has_advantage variable to true
******************************************************************/
void Attack::set_advantage()
{
	has_advantage = true;
	return;
}


/******************************************************************
Sets the has_disadvantage variable to true
******************************************************************/
void Attack::set_disadvantage()
{
	has_disadvantage = true;
	return;
}


/******************************************************************
Sets the number of damage dice
******************************************************************/
void Attack::set_number_dice( int num_dice )
{
	dmg_dice_num = num_dice;
	return;
}


/******************************************************************
Sets the damage dice sides
******************************************************************/
void Attack::set_dice_sides( int dice_sides )
{
	dmg_dice_sides = dice_sides;
	return;
}


/******************************************************************
Sets the damage modifier
******************************************************************/
void Attack::set_dmg_mod( int mod )
{
	dmg_mod = mod;
	return;
}


/******************************************************************
Sets the attack modifier
******************************************************************/
void Attack::set_attack_mod( int mod )
{
	attack_mod = mod;
	return;
}


/******************************************************************
Outputs the stats to the screen or a file
******************************************************************/
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


/******************************************************************
Returns the value in has_advantage
******************************************************************/
bool Attack::advantage()
{
	return has_advantage;
}


/******************************************************************
Returns the value in has_disadvantage
******************************************************************/
bool Attack::disadvantage()
{
	return has_disadvantage;
}


/******************************************************************
Returns the number of damage dice
******************************************************************/
int Attack::number_dice()
{
	return dmg_dice_num;
}


/******************************************************************
Return the number of sides for the damage dice
******************************************************************/
int Attack::dice_sides()
{
	return dmg_dice_sides;
}


/******************************************************************
Returns the damage modifier
******************************************************************/
int Attack::get_dmg_mod()
{
	return dmg_mod;
}


/******************************************************************
Returns the attack modifier
******************************************************************/
int Attack::get_attack_mod()
{
	return attack_mod;
}


/******************************************************************
Returns the message
******************************************************************/
string Attack::get_message()
{
	return message;
}


/******************************************************************
Allows you to set attacks equal to each other
******************************************************************/
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
