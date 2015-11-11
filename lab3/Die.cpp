/*********************************************************************
** Program Filename:	Die.cpp
** Author:				Shawn Hillyer
** Date:				09/24/2015
** Description:			Implementation for Die class. Simulates the
**    roll on a die with at least 4 sides.
** Input:	N/A
** Output:  N/A
********************************************************************/
#include <cstdlib>
#include "Die.hpp"


/*********************************************************************
** Function:  Die()
** Description: Default constructor
** Parameters:   int sides; defaults to 6
** Pre-Conditions:  Called during instantiation
** Post-Conditions: New Die object created fully initialized
********************************************************************/
Die::Die(int sides)
{
	set_num_sides(sides);
}


/*********************************************************************
** Function: set_num_sides()
** Description: Validates and sets num_sides member variable
** Parameters:  int sides is validated and assigned to num_sides
** Pre-Conditions: object must be instantiated to call; private func.
** Post-Conditions: num_sides will be initialized
********************************************************************/
void Die::set_num_sides(int sides)
{
	if (sides < 4) // smallest number of sides on a die is 4
	{
		num_sides = 4;
	}
	else
	{
		num_sides = sides;
	}
}


/*********************************************************************
** Function:  roll()
** Description:  Simulates a roll of a fair die
** Parameters:		None
** Pre-Conditions:	Object must be instantiated
** Post-Conditions: Returns an int from range [1, num_sides] inclusive
********************************************************************/
int Die::roll()
{
	int roll = rand() % num_sides + 1; //
	return roll;
}
