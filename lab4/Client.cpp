/*********************************************************************
** Program Filename: Client.cpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/15/2015
** Description:      A Client class to handle a recurision function testing.
**                   Handles the menu and logic branching.
** Input:            User input at terminal to select options/enter vals
** Output:           Prints results of the function calls and a menu
**                   for user to select options
********************************************************************/
#include "Client.hpp"

/*********************************************************************
** Function:         main_loop()
** Description:      Prompts for and validates user choice for next action
** Parameters:       None
** Pre-Conditions:   Client must exist
** Post-Conditions:  main_loop executes
********************************************************************/
Client::Client()
{
	main_loop();
}

void Client::main_loop()
{
  /* Menu variables to validate input */
	const int FIRST_CHOICE = 1, LAST_CHOICE = 5;
  int menu_choice = 0;

	/* Variables to hold arguments/return values */
	std::string input_string = "", // to catch argument to send to reverse_string()
							new_string = "";   // to catch return value of reverse_string()
	double* p_array;        // pointer to an array to catch dynamic array
	double sum = 0;         // to catch return value of sum_array()
	int tri_num = 0,        // to catch argument to send to triangle_number()
	    tri_result = 0;     // to catch return value of triangle_number()
	int array_size = 0;

  while (menu_choice != LAST_CHOICE)
  {
		array_size = 0; // reinitialize to ensure its passed as zero to prompt_array()
    do
    {
      print_menu();
      std::cin >> menu_choice;
    } while (!in_range(menu_choice, FIRST_CHOICE, LAST_CHOICE));
		std::cin.ignore(100, '\n'); // ignore the newline in buffer

		/* Call appropriate function */
    switch (menu_choice)
    {
    case 1:
			input_string = prompt_string();
			std::cout << "Calling Recursive::reverse_string(" << input_string << ") ...\n";
      new_string = Recursive::reverse_string(input_string);
			std::cout << "\nThe return value of the function call is also: \n\"" << new_string << "\"\n";
      break;
    case 2:
			p_array = prompt_array(array_size);
      sum = Recursive::sum_array(p_array, array_size);
			std::cout << "Sum of the array values is " << sum << "\n";
			delete [] p_array; // free memory
      break;
		case 3:
			p_array = prompt_array_alt(array_size);
			sum = Recursive::sum_array(p_array, array_size);
			std::cout << "Sum of the array values is " << sum << "\n";
			delete [] p_array; // free memory
			break;
		case 4:
			tri_num = prompt_triangle();
      tri_result = Recursive::triangle_number(tri_num);
			std::cout << "A triangle with " << tri_num << " rows will have " << tri_result << " items.\n";
      break;
    case LAST_CHOICE:
      exit();
      break;
    }
  }
}


/*********************************************************************
** Function:         print_menu()
** Description:      Prints main menu
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Menu will be displayed on terminal
********************************************************************/
void Client::print_menu() const
{
  std::cout << "\nWhat would you like to do?\n";
	std::cout << "1: Reverse a String\n";
	std::cout << "2: Calculate the sum of an array (pick number of values before entering)\n";
	std::cout << "3: Calculate sum of array (Free enter values)\n";
	std::cout << "4: Find the triangular number for a triangle n rows high\n";
	std::cout << "5: Quit\n";
	std::cout << ">> ";
}


/*********************************************************************
** Function:         in_range()
** Description:      Checks if int 'value' is in range [min,max] inclusive
** Parameters:       int value, in min, and int max
** Pre-Conditions:   Value to check and a range must be passed in
** Post-Conditions:  Returns true if min <= value <= max, false otherwise
********************************************************************/
bool Client::in_range(const int value, const int min, const int max) const
{
	if (value >= min && value <= max)
		return true;
	else
		return false;
}


/*********************************************************************
** Function:         prompt_string()
** Description:      Prompt user for a string and return to caller
** Parameters:       none
** Pre-Conditions:   Client must exist
** Post-Conditions:  Returns a string.
********************************************************************/
std::string Client::prompt_string() const
{
	std::string user_string = "";
	std::cout << "Enter a string:\n>";
	std::getline(std::cin, user_string);
	return user_string;
}


/*********************************************************************
** Function:         prompt_array()
** Description:      Prompt user for values to store in an array and
**                   return a dynamically allocated array of doubles
**                   This version prompts user to indicate how many
**                   values they intend to enter before doing input
**                   The value passed in is the size of array and must
**                   be used to determine size of array outside of this scope
** Parameters:       a counter of type int with value 0 passed in by ref
** Pre-Conditions:   Client must exist
** Post-Conditions:  Returns dyanamic array of doubles
********************************************************************/
double* Client::prompt_array(int& num_values) const
{
	const int MIN_COUNT = 1, MAX_COUNT = 100;
	do
	{
		std::cout << "How many values of type double would you like to enter? (";
		std::cout << MIN_COUNT << "-" << MAX_COUNT << ")\n>";
		std::cin >> num_values;
	} while(!in_range(num_values, MIN_COUNT, MAX_COUNT));

	/* Now make the array and get values from user */
	double* rtrn_array = new double[num_values];
	for (int i = 0; i < num_values; i++)
	{
			std::cout << "Enter value " << i+1 << " of " << num_values << ": > ";
			std::cin >> rtrn_array[i];
	}
	return rtrn_array;
}


/*********************************************************************
** Function:         prompt_array_alt()
** Description:      Prompt user for values to store in an array and
**                   return a dynamically allocated array of doubles
**                   This version allows user to input until sentilel
**                   value is input.
**                   The value passed in is the size of array and must
**                   be used to determine size of array outside of this scope
** Parameters:       none
** Pre-Conditions:   Client must exist
** Post-Conditions:  Returns dyanamic array of doubles
********************************************************************/
double* Client::prompt_array_alt(int& counter) const
{
	const double SENTINEL = -9999; // enters this value to end loop
	std::vector<double> values;
	double input = 0;

	std::cout << "Enter values to calculate the sum. Enter << " << SENTINEL << " to stop entering values.\n";
	do
	{
		std::cout << "Enter value " << counter + 1 << ": >";
		std::cin >> input;

		if (input != SENTINEL) // don't add/count SENTINEL value
		{
			values.push_back(input);
			counter++;
		}
	} while(input != SENTINEL);

	/* If user entered no values then use default array of 1 element */
	if (counter == 0)
	{
		std::cout << "You entered no values. Using array with 1 value (1).\n";
		double* p_array = new double[1];
		p_array[0] = 1;
		counter++; // Prevents segmentation fault back in main_loop()
		return p_array;
	}
  /* create array, move values from vector into arrray */
	else
	{
		double* p_array = new double[counter];
		for (int i = 0; i < counter; i++)
		{
			p_array[i] = values.at(i);
		}
		return p_array;
	}
}

/*********************************************************************
** Function:         prompt_triangle()
** Description:      Prompt user for value to calculate its triangular
**                   number.
** Parameters:       none
** Pre-Conditions:   Client must exist
** Post-Conditions:  Returns int value
********************************************************************/
int Client::prompt_triangle() const
{
	int tri_rows = 0;
	const int MIN_ROWS = 1, MAX_ROWS = 113500;
	do
	{
		std::cout << "Enter number of rows for a triangle ( " << MIN_ROWS << "-" << MAX_ROWS << ")\n>";
		std::cin >> tri_rows;
	} while(!in_range(tri_rows, MIN_ROWS, MAX_ROWS));

	return tri_rows;
}

/*********************************************************************
** Function:         exit()
** Description:      Executes any code prior to quitting the main loop
** Parameters:       none
** Pre-Conditions:   Client must exist
** Post-Conditions:  Client should stop executing code; drop into main()
********************************************************************/
void Client::exit() const
{
  std::cout << "Exiting program.\n\n";
}
