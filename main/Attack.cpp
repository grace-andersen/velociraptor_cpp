#include "Attack.h"

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
