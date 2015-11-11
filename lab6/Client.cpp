/*********************************************************************
** Program Filename: Client.cpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/28/2015
** Description:      A Client class to handle input for StackList and
**                   QueueList class testing purposes
** Input:            User input at terminal to select options
** Output:           Prints values to demonstrate lists
********************************************************************/
#include "Client.hpp"

/*********************************************************************
** Function:         Client()
** Description:      Instantiate the client and call main_loop()
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  main_loop() will be called and Client will exist
********************************************************************/
Client::Client()
{
	main_loop();
}


/*********************************************************************
** Function:         main_loop()
** Description:      Prompts for and validates user choice for next action
** Parameters:       None
** Pre-Conditions:   Client must exist
** Post-Conditions:  Calls other methods as appropriate
********************************************************************/
void Client::main_loop()
{
	const int first_choice = 1, last_choice = 5;
	int menu_choice = 0;

	while (menu_choice != last_choice)
	{
		do
		{
			print_menu();
			std::cin >> menu_choice;
		} while (!in_range(menu_choice, 1, last_choice));
		std::cin.ignore(100, '\n');
		switch (menu_choice)
		{
		case 1:
			run_simulation();
			break;
		case 2:
			stacklist_demo();
			break;
		case 3:
		  run_simulation2();
			break;
		case 4:
			queuelist_demo();
			break;
		case last_choice:
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
	std::cout << "1: StackList automated test\n";
	std::cout << "2: StackList manual test\n";
	std::cout << "3: QueueList automated test\n";
	std::cout << "4: QueueList manual test\n";
	std::cout << "5: Quit\n";
	std::cout << ">> ";
}


/*********************************************************************
** Function:         print_menu_b()
** Description:      Prints main menu
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Menu will be displayed on terminal
********************************************************************/
void Client::print_menu_b() const
{
	std::cout << "\n\nSelect an operation\n";
	std::cout << "1: StackList: Add a double value\n";
	std::cout << "2: StackList: Remove value from stack\n";
	//std::cout << "3: Run Custom Simulation\n";
	std::cout << "4: Main Menu\n";
	std::cout << ">> ";
}

/*********************************************************************
** Function:         run_simulation()
** Description:      Runs automated tests
** Parameters:       none
** Pre-Conditions:   .
** Post-Conditions:  Prints tests to screen
********************************************************************/
void Client::run_simulation()
{
	const int SIZE = 20;
	std::cout << "Running automated test...\n";

	int* values = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		values[i] = i;
	}

	StackList<int> int_stack;
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Calling int_stack.add(" << values[i] << ")\n";
		int_stack.add(values[i]);
	}

	std::cout << "Calling int_stack.remove()... should see values in reverse.\n";
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << int_stack.remove();
		std::cout << ((i == SIZE - 1) ? (".\n") : (", "));
	}

	for (int i = 0; i < SIZE/2; i++)
	{
		std::cout << "Calling int_stack.add(" << values[i]*2 << ")\n";
		int_stack.add(values[i]*2);
	}

	std::cout << "Calling int_stack.remove()... should see values in reverse.\n";
	for (int i = 0; i < SIZE/4; i++)
	{
		std::cout << int_stack.remove();
		std::cout << ((i == SIZE - 1) ? (".\n") : (", "));
	}

	delete [] values;
}

/*********************************************************************
** Function:         run_simulation2()
** Description:      RUn automated test on queue
** Parameters:       none
** Pre-Conditions:   .
** Post-Conditions:  Prints tests to screen
********************************************************************/
void Client::run_simulation2()
{
	const int SIZE = 10;
	std::cout << "Running automated test...\n";

	int* values = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		values[i] = i;
	}

	QueueList<int> int_queue;
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Calling int_queue.add(" << values[i] << ")\n";
		int_queue.add(values[i]);
	}

	std::cout << "Calling int_queue.remove()... should see values in same order added.\n";
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << int_queue.remove();
		std::cout << ((i == SIZE - 1) ? (".\n") : (", "));
	}

	for (int i = 0; i < SIZE/2; i++)
	{
		std::cout << "Calling int_queue.add(" << values[i]*2 << ")\n";
		int_queue.add(values[i]*2);
	}

	std::cout << "Calling int_queue.remove()... should see values in same order added.\n";
	for (int i = 0; i < SIZE/4; i++)
	{
		std::cout << int_queue.remove();
		std::cout << ((i == SIZE - 1) ? (".\n") : (", "));
	}

	delete [] values;
}


/*********************************************************************
** Function:         stacklist_demo()
** Description:      Lets user add doubles to the StackList and pop them off
** Parameters:       none
** Pre-Conditions:   none
** Post-Conditions:  Displays results
********************************************************************/
void Client::stacklist_demo()
{
	StackList<double> double_stack;

	double input = 0;
	while (input != -1)
	{
		std::cout << "Enter a value and press [enter] to add to StackList, -1 to stop: ";
		std::cin >> input;
		if (input != -1)
			double_stack.add(input);
	}

	try
	{
		std::cout << "Enter [enter] to continue pop values, or Q to quit.\n";

		char keypress = 'z';
		while (toupper(keypress) != 'Q')
		{
				keypress = std::cin.get();
				std::cout << "Removed: " << double_stack.remove() << "\n";
		}
	}
	catch(std::string msg)
	{
		std::cout << msg;
	}
}


/*********************************************************************
** Function:         stacklist_demo()
** Description:      Lets user add doubles to the StackList and pop them off
** Parameters:       none
** Pre-Conditions:   none
** Post-Conditions:  Displays results
********************************************************************/
void Client::queuelist_demo()
{
	QueueList<double> double_queue;

	double input = 0;
	while (input != -1)
	{
		std::cout << "Enter a value and press [enter] to add to QueueList, -1 to stop: ";
		std::cin >> input;
		if (input != -1)
			double_queue.add(input);
	}

	try
	{
		std::cout << "Enter [enter] to continue pop values from front of list, or Q to quit.\n";

		char keypress = 'z';
		while (toupper(keypress) != 'Q')
		{
				keypress = std::cin.get();
				std::cout << "Removed: " << double_queue.remove() << "\n";
		}
	}
	catch(std::string msg)
	{
		std::cout << msg;
	}
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


/*********************************************************************
** Function:         main()
** Description:      Entry point for program
** Parameters:       Uses none
** Pre-Conditions:   None
** Post-Conditions:  Program runs
********************************************************************/
int main(int argc, char** argv)
{
	Client client;
	return 0;
}
