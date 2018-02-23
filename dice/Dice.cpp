#include "Dice.h"

//
int Dice::get_random_range()
{
    random_device rd;
    mt19937 gen{rd()};
    uniform_int_distribution<> dis{ 1, num_sides };
    return dis(gen);
}



int Dice::roll()
{
    return get_random_range();
}



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



int Dice::number_sides()
{
    return num_sides;
}



int Dice::sum_roll_n( int num_dice )
{
    int sum = 0;
    for( int i = 0; i < num_dice; i++ )
    {
        sum +=roll();
    }
      return sum;
}
