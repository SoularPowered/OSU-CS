/*********************************************************************
** Program Filename: recuisrive_funcs.cpp		[Main Entrypoint]
** Author:           Shawn Hillyer
** Date:             10/15/2015
** Description:      Entrypoint to instantiate Client class for Recursive
**                   functions program
** Input:            None
** Output:           See Client class
********************************************************************/
#include "Client.hpp"

void print_author();

int main(int argc, char const *argv[])
{
  Client program;

  print_author();
  return 0;
}


/*********************************************************************
** Function:         print_author()
** Description:      Prints author information
** Parameters:       None
** Pre-Conditions:   none
** Post-Conditions:  n/a
********************************************************************/
void print_author()
{
	std::cout << "Created by Shawn S. Hillyer\n";
	std::cout << "Shawn (dot) Hillyer (at) Gmail (dot) com\n";
	std::cout << "Date: 10/15/2015\n";
	std::cout << "Github.com/Soularpowered\n";
}
