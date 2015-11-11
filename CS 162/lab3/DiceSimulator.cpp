/*********************************************************************
** Program Filename:  DiceSimulator.cpp
** Author:            Shawn Hillyer
** Date:              09/24/2015
** Description:       Testing client to test Die and loaded_die classes
** Input:             User input at keyboard
** Output:            Prints results to screen
********************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Die.hpp"
#include "LoadedDie.hpp"

/* Function Prototypes */
void display_menu();
bool in_range(const int value, const int min, const int max);
void auto_test(int sample_size, int die_sides);
void manual_test();
void print_rolls(int rolls[], int num_rolls, std::string label);
int sum_array(int arr[], int size);

/*********************************************************************
** Function:	main()
** Description:	Prompts user and tests out the classes
** Parameters:	None
** Pre-Conditions:	Main entry for program
** Post-Conditions:	Prints result of tests or quits program.
********************************************************************/
int main()
{
	srand(time(0));			// rand() is caled in the Die and loaded_die

	std::cout << "Welcome to Dice Simulator.\n";

	/* Print menu and process choice until user quits */
	int menu_choice = 0;
	while (menu_choice != 3)
	{
		/* Validate input */
		do
		{
			display_menu();
			std::cin >> menu_choice;
		} while (!in_range(menu_choice, 1, 3));

		switch (menu_choice)
		{
		case 1:
			auto_test(1000, 100);
			break;
		case 2:
			manual_test();
			break;
		case 3:
			std::cout << "Exiting program.\n\n";
			break;
		}
	}
	return 0;
}


/*********************************************************************
** Function:	display_menu()
** Description: Prints a menu for user to read
** Parameters:	None
** Pre-Conditions: None
** Post-Conditions: None
********************************************************************/
void display_menu()
{
	std::cout << "\nWhat would you like to do?\n";
	std::cout << "1: Run the automated test\n";
	std::cout << "2: Run a manual test\n";
	std::cout << "3: Quit\n";
	std::cout << ">> ";
}


/*********************************************************************
** Function: in_range()
** Description:	Validates that a value is in a range passed to function
** Parameters: value (variable to check) and a min and max value (inclusive)
** Pre-Conditions: Value must exist
** Post-Conditions: Returns true if value is >= min && <= max, false otherwise
********************************************************************/
bool in_range(const int value, const int min, const int max)
{
	if (value >= min && value <= max)
		return true;
	else
		return false;
}


/*********************************************************************
** Function:	auto_test()
** Description: Runs simulation of both die types
** Parameters:  int sample_size is number of rolls, die_sides is # of
**    sides each die should have.
** Pre-Conditions: None
** Post-Conditions: Results will have printed and all memory freed.
********************************************************************/
void auto_test(int sample_size, int die_sides)
{
	/* Create a fair and loaded die, set up arrays to store results */
	Die fair_die(die_sides);
	LoadedDie loaded_die(die_sides);
	int *fair_rolls = new int[sample_size],
		*loaded_rolls = new int[sample_size];

	/* Run simulation */
	for (int i = 0; i < sample_size; i++)
	{
		fair_rolls[i] = fair_die.roll();
		loaded_rolls[i] = loaded_die.roll();
	}

	/* Calculate the sum and average of the two sets of die rolls */
	int		fair_total = sum_array(fair_rolls, sample_size),
			loaded_total = sum_array(loaded_rolls, sample_size);
	double	fair_average = (static_cast<double>(fair_total) / sample_size),
			loaded_average = (static_cast<double>(loaded_total) / sample_size),
			average_difference = loaded_average - fair_average;
	/* Print results */
	std::cout << "\nRunning simulation...\n\n";

	print_rolls(fair_rolls, sample_size, "Fair Die");
	print_rolls(loaded_rolls, sample_size, "Loaded Die");

	std::cout << "The Fair Die total: " << fair_total << "\nFair die - Average of " << sample_size << " rolls: " << fair_average << "\n\n";
	std::cout << "The loaded die total: " << loaded_total << "\nLoaded die - Average of " << sample_size << " rolls: " << loaded_average << "\n\n";

	std::cout << "The loaded die averages a roll " << average_difference << " higher than the fair die.\n";

	/* Free the memory */
	delete [] fair_rolls;
	delete [] loaded_rolls;
}


/*********************************************************************
** Function:	manual_test()
** Description:	Get valid user input and pass to auto_test()
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Will pass valid input to auto_test() and run tests
********************************************************************/
void manual_test()
{
	int die_sides = 0,
		num_rolls = 0;
	const int max_sides = 2500000;

	/* Prompt for and validate user input, then call the test */
	do
	{
		std::cout << "How many sides should the pair of dice have? Minimum is 4.\n>>";
		std::cin >> die_sides;
	} while (!in_range(die_sides, 4, max_sides));

	do
	{
		std::cout << "How many times shall the dice be cast? Minimum is 1.\n>>";
		std::cin >> num_rolls;
	} while (!in_range(num_rolls, 1, max_sides));

	std::cout << "Simulating " << num_rolls << " rolls using " << die_sides << "-sided dice.\n";
	std::cout << "Press any key to begin.\n>>";

	auto_test(num_rolls, die_sides);
}


/*********************************************************************
** Function:	print_rolls()
** Description:	Prints results of the rolls and a sum total
** Parameters: An array of rolls[], int num_rolls, and a string to label
**    the data
** Pre-Conditions: A Die or loaded_die object should have been created
**    and stored result of at least 1 roll in an array for processing.
** Post-Conditions: Results printed to screen.
********************************************************************/
void print_rolls(int rolls[], int num_rolls, std::string label)
{
	std::cout << "Rolls for the " << label << "dice: " << std::endl;
	std::cout << "---------" << std::endl;
	int roll_total = 0; // accumulator

	for (int i = 0; i < num_rolls; i++)
	{
		std::cout << "Roll " << i << ": " << rolls[i] << "\n";
		roll_total += rolls[i];
	}

	std::cout << "\nTotal of all " << label << " rolls: " << roll_total << "\n";
	std::cout << "Average of all " << label << " rolls: " << static_cast<double>(roll_total) / num_rolls << "\n";
}


/*********************************************************************
** Function:	sum_array()
** Description:	Calculates the sum of an integer array
** Parameters: int arr[] and its size(int)
** Pre-Conditions: Pre-existing array and its (known) size
** Post-Conditions: Returns the total as an int.
********************************************************************/
int sum_array(int arr[], int size)
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		total += arr[i];
	}
	return total;
}
