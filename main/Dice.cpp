#include "Dice.h"

//private function that deals with random number generation
int Dice::get_random_range()
{
    random_device rd;
    mt19937 gen{rd()};
    uniform_int_distribution<> dis{ 1, num_sides };
    return dis(gen);
}


//public function that calls whatever random method is implemented
int Dice::roll()
{
    return get_random_range();
}


//roll num_dice number of dice and keep either the highest or lowest
//depending on whether an 'l' or an 'h' is passed in. 
int Dice::roll_n_k1(  int num_dice, char high_or_low )
{
    int extreme = 0;
    int result = 0;
    
    if( tolower(high_or_low) == 'l' )
    {
        extreme = 20;
    }
    else
    {
        extreme = 1;
    }
    
    for( int i = 0; i < num_dice; i++ )
    {
        result = roll();
        if( (tolower(high_or_low) == 'l' ) && result < extreme )
        {
            extreme = result;
        }
        else if( ( tolower(high_or_low) == 'h' ) && result > extreme )
        {
            extreme = result;
        }
    }
    return extreme;
}


//return the private value containing the initialized number of sides
int Dice::number_sides()
{
    return num_sides;
}


//rolls n dice, returns the sum of the values
int Dice::sum_roll_n( int num_dice )
{
    int sum = 0;
    for( int i = 0; i < num_dice; i++ )
    {
        sum +=roll();
    }
      return sum;
}
