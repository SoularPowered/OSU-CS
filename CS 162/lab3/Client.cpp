/*********************************************************************
** Program Filename: Client.cpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      A Client class to handle a Dice game using the
**                   terminal for input and output. Handles main
**                   game loop and main menu to start a game of DiceWar
** Input:            User input to select the type of dice, players, etc.
** Output:           Will print results of two players rolls and the winner
**                   of the game.
********************************************************************/
#include "Client.hpp"

/*********************************************************************
** Function:         main_loop()
** Description:      Prompts for and validates user choice for next action
** Parameters:       None
** Pre-Conditions:   Client must exist
** Post-Conditions:  Program will proceed to call methods on List grociers
**                   until user decides to quit.
********************************************************************/
Client::Client()
{
	main_loop();
}

void Client::main_loop()
{
  const int first_choice = 1, last_choice = 2;
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
      game.start_new_game();
      break;
      break;
    case last_choice:
      game.quit();
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
void Client::print_menu()
{
  std::cout << "\nWelcome to DiceWar! \n\nMake a selection...\n";
	std::cout << "1: Start a New Game\n";
	std::cout << "2: Quit\n";
	std::cout << ">> ";
}


/*********************************************************************
** Function:         in_range()
** Description:      Checks if int 'value' is in range [min,max] inclusive
** Parameters:       int value, in min, and int max
** Pre-Conditions:   Value to check and a range must be passed in
** Post-Conditions:  Returns true if min <= value <= max, false otherwise
********************************************************************/
bool Client::in_range(const int value, const int min, const int max)
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
void Client::exit()
{
  std::cout << "Exiting program.\n\n";
}
