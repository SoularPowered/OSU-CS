/*********************************************************************
** Program Filename: Client.cpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             11/13/2015
** Description:      A Client class to handle user input and program
**                   output - this variant handles a queue Simulation
** Input:            User input at terminal to select options
** Output:           Responds to user iput appropriately
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
	this->main_menu.load_menu_file("main.menu");
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
	int menu_choice = 0;
	int value = -1;
	in_range(5,1,4);

	do
	{
		menu_choice = this->main_menu.prompt_user();
		std::cin.ignore(100, '\n');

		switch (menu_choice)
		{
		case 1: // Run a simulation with a single queue & n servers
			{
				int num_lines = 1;
				int servers = 0;
				do
				{
					std::cout << "How many servers should there be? (1 to 1,000)";
					std::cin >> servers;
				} while (!in_range(servers, 1, 1000));

				LineSimulator* single = new LineSimulator("Single Queue", num_lines, servers, 10);
				single->run_simulation();
			}
			break;
		case 2: // Run a simulation with a multiple queues
			{
				int num_lines = 0;
				do
				{
					std::cout << "How many servers should there be? (1 to 1,000)";
					std::cin >> num_lines;
				} while (!in_range(num_lines, 1, 1000));

				LineSimulator* multiple = new LineSimulator("Multiple Queue", num_lines, num_lines, 10);
				multiple->run_simulation();
			}
			break;
		}
	} while (menu_choice != this->main_menu.get_quit_value());

	exit();
}


/*********************************************************************
 ** Function:         in_range()
 ** Description:      Validates min <= val <= max
 ** Parameters:       3 integers for range
 ** Pre-Conditions:   .
 ** Post-Conditions:  Returns true or false
 ********************************************************************/
bool Client::in_range(const int val, const int min, const int max) const
{
	return (val >= min && val <= max);
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
	std::cout << "Created by Shawn S. Hillyer\n";
	std::cout << "Shawn (dot) Hillyer (at) Gmail (dot) com\n";
	std::cout << "Date: 11/20/2015\n";
	std::cout << "Github.com/Soularpowered\n";
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
	srand(time(0));
	Client client;
	return 0;
}
