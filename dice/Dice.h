#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <chrono>

using namespace std;

class Dice {
  
  public: 
  //constructor
  Dice(int sides = 0):num_sides(sides)
  {
    srand(time(NULL));
  }

  //roll a single dice of num_sides sides 
  int roll();
  //roll num_dice and keep either the highest or lowest
  int roll_n_k1( int num_dice, char high_or_low );
  //returns the current number of sides
  int number_sides();
  //sum up n dice results
  int sum_roll_n( int num_dice );
  
  
  private:
  //stores the number of sides of the dice
  int num_sides;
  //gets a random number in range of 1 to num_sides
  int get_random_range();
};