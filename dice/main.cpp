#include <iostream>
#include "Dice.h"



int main( int argc, char ** argv ) 
{
  	Dice d_20(stol(argv[1],nullptr));
  	cout << d_20.roll() << endl;
  	return 0;
}