#include <iostream>
#include "Dice.h"



int main() 
{
  Dice d_20(20);
  for( int i = 0; i < 20; i++ )
    cout << d_20.roll() << " ";
  return 0;
}