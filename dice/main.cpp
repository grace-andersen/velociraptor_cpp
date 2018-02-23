#include <iostream>
#include "Dice.h"



int main() 
{
	int num_sides;

	cout << "Enter the number of sides for your dice: ";
	cin >> num_sides;
  	Dice d_20( num_sides );
  	cout << "You rolled a: " << d_20.roll() << endl;
  	return 0;
}