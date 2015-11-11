/*********************************************************************
** Program Filename: Client.cpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/08/2015
** Description:      A Client class to handle a List of grocery Items.
**                   Prints the menu and gets choices and generally
**                   handles main program logic.
** Input:            User input at terminal to set up the Items
** Output:           Creates a single List with 0 to many Items to screen.
**                   Prints menu to screen.
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
** Post-Conditions:  Program will proceed to call methods on List grociers
**                   until user decides to quit.
********************************************************************/
void Client::main_loop()
{
  const int first_choice = 1, last_choice = 4;
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
      groceries.add_item();
      break;
    case 2:
      groceries.remove_item();
      break;
    case 3:
      groceries.print_list();
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
	std::cout << "1: Add an item\n";
	std::cout << "2: Remove an item\n";
	std::cout << "3: Print the list\n";
	std::cout << "4: Quit\n";
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
