#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Die.hpp"
#include "LoadedDie.hpp"

int main(int argc, char* argv[])
{
	srand(time(NULL));		// Seed the RNG



	/* Keep track of number of rolls, a temp value for each role, and a sum of all rolls for each die to be used in calculation of the average */
	int num_Rolls,
		sides,
		clean_Roll,
		clean_Sum = 0,
		dirty_Roll,
		dirty_Sum = 0;

	// Prompt user for number of sides for the dice and set them

	std::cout << "How many sides should our dice have?" << std::endl;
	std::cin >> sides;
	Die clean_Die = Die(sides);		// Use 20-sided dice
	LoadedDie dirty_Die = LoadedDie(sides);
	

	// Prompt user for number of times to roll the die

	std::cout << "How many times should we roll the dice?" << std::endl;
	std::cin >> num_Rolls;

	for (int i=0; i<num_Rolls; i++)
	{
		clean_Roll = clean_Die.roll();
		dirty_Roll = dirty_Die.roll();
		std::cout << "The clean dice rolled a " << clean_Roll << ".\n";
		std::cout << "The dirty dice rolled a " << dirty_Roll << ".\n";
		clean_Sum += clean_Roll;
		dirty_Sum += dirty_Roll;
	}


	/* Give sum of rolls for each die, and give average roll of each die. */

	std::cout << "The sum of the clean dice rolls is " << clean_Sum << " and the average roll was " << static_cast<double>(clean_Sum) / num_Rolls <<  std::endl;

	std::cout << "The sum of the dirty dice rolls is " << dirty_Sum << " and the average roll was " << static_cast<double>(dirty_Sum) / num_Rolls <<  std::endl;


	return 0;
}
