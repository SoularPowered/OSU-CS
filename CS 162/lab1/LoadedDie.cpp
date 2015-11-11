/*********************************************************************
** Program Filename:	LoadedDie.cpp
** Author:				Shawn Hillyer
** Date:				09/24/2015
** Description:			Implementation for LoadedDie class. Simulates
**		a simple die with an unfair chance to roll higher than
**		a fair die (equal chance for each side).
** Input:				N/A
** Output:				N/A
********************************************************************/
#include <cstdlib>
#include "LoadedDie.hpp"


/*********************************************************************
 ** Function:			LoadedDie
 ** Description:		Default Constructor
 ** Parameters:			int (optional) - sets num_sides, defaults to 6
 ** Pre-Conditions:
 ** Post-Conditions:	LoadedDie will have all data initalized
********************************************************************/
LoadedDie::LoadedDie(int sides)
{
	set_num_sides(sides);
	value_weights = new double[sides];
	load_die(.80);		// Base probability that a die will tip to a higher value.
}


/*********************************************************************
** Function:		~LoadedDie
** Description:		Deconstructor, deallocate value_weights
** Parameters:		None
** Pre-Conditions:
** Post-Conditions: memory allocated for value_weights is cleared
********************************************************************/
LoadedDie::~LoadedDie()
{
	if (num_sides > 0)		// Dummy proofing - to ensure only delete if the value_weights array was initialized
	{
		delete [] value_weights;
	}
}


/*********************************************************************
** Function:	LoadedDie(LoadedDie)
** Description: Overloaded copy constructor
** Parameters:  &obj; only called when object is being copied
** Pre-Conditions: A fully initalized LoadedDie object
** Post-Conditions: A deeply-copied second LoadedDie object
********************************************************************/
LoadedDie::LoadedDie(LoadedDie &obj)
{
	num_sides = obj.num_sides;
	value_weights = new double[num_sides];
	for (int i = 0; i < num_sides; i++)
	{
		value_weights[i] = obj.value_weights[i];
	}
}


/*********************************************************************
** Function: set_num_sides()
** Description: Validates and sets num_sides member variable
** Parameters:  int sides is validated and assigned to num_sides
** Pre-Conditions: object must be instantiated to call; private func.
** Post-Conditions: num_sides will be initialized
********************************************************************/
void LoadedDie::set_num_sides(int sides)
{
	if (sides < 4)		// smallest number of sides on a LoadedDie is 4
	{
		num_sides = 4;
	}
	else
	{
		num_sides = sides;
	}
}


/*********************************************************************
** Function: roll()
** Description: Returns an int from range [1, num_sides], weighted to
**		give a value higher than a "fair" die would give
** Parameters:		None.
** Pre-Conditions:
** Post-Conditions: Returns an int.
********************************************************************/
int LoadedDie::roll()
{
	int chanceToRollMax = 50;	// expressed as a whole number so easier to evaluate

	int roll = rand() % num_sides + 1;
	if (load_worked(roll))
	{
		/* 25 % chance to get a max roll, otherwise it is increase by 1/2 the value from roll to num_sides*/
		if (rand() % 4 == 0)
		{
			return num_sides;
		}
		else
		{
			return roll + (0.5 * (num_sides - roll));	// result is a value halfway between fair roll and max value
		}

	}
	return roll;
}


/*********************************************************************
** Function: load_worked()
** Description: Decides if the loaded die "worked" (adds randomness to cheat)
** Parameters: pass in a valid roll; passed by the roll() method.
** Pre-Conditions: Must be called by roll(); Private method.
** Post-Conditions: Returns true or false if the load worked
********************************************************************/
bool LoadedDie::load_worked(int clean_roll)
{
	bool load_works = false;
	if ((rand() & 100 + 1) <= value_weights[clean_roll - 1])
	{
		load_works = true;
	}
	return load_works;
}


/*********************************************************************
** Function:  load_die()
** Description: Initializes value_weights with the chance that the load
**    will work
** Parameters:  Accepts a weight passed by constructor.
** Pre-Conditions:  Instantiation. Private method called by constructor
** Post-Conditions: value_weights array will  have values stored atll all indexes
********************************************************************/
void LoadedDie::load_die(double weight)
{
	/* Load die so all faces have a chance of rolling higher except last face */
	int top_third_index = 2 * (num_sides / 3);
	for (int i = 0; i < num_sides - 2; i++)
	{
		if (i <= top_third_index)
		{
			value_weights[i] = weight * 100;
		}
		else
		{
			value_weights[i] = weight * 80;
		}
	}
	/* Weight for highest face of die is 0 to ensure we don't "roll a 7" on a 6-sided die */
	value_weights[num_sides - 1] = 0;
}
