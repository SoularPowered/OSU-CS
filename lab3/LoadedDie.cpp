/*********************************************************************
** Program Filename: LoadedDie.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      Modified code from another student for a LoadedDie
**                   converted to inherit from Die class of mine
** Input:            None or one int for num of sides
** Output:           Can call rand to get an int from 1 to num_sides
********************************************************************/

#include "LoadedDie.hpp"
#include <stdlib.h>

LoadedDie::LoadedDie(int sides = 6) : Die(sides)
{
	;
}

/*********************************************************************
** Function:        roll()
** Description:     Simulates a roll of a Loaded die (skews results)
** Parameters:      None
** Pre-Conditions:	Object must be instantiated
** Post-Conditions: Returns an int from range [1, num_sides] inclusive
********************************************************************/

int LoadedDie::roll()
{
	int result = (rand() % num_sides) + 1,
		midpoint = (num_sides / 2);
	if (result < midpoint)
	{
		if (rand() % 2 == 0)
			result = num_sides;
	}
	return result;
}
