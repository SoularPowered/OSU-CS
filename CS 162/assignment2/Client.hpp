/*********************************************************************
** Program Filename: Client.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/08/2015
** Description:      A Client class to handle a List of grocery Items.
**                   Prints the menu and gets choices and generally
**                   handles main program logic.
** Input:            User input at terminal to set up the Items
** Output:           Creates a single List with 0 to many Items to screen.
**                   Prints menu to screen.
********************************************************************/
#ifndef SSHILLYER_CLIENT_HPP
#define SSHILLYER_CLIENT_HPP

#include "List.hpp"
#include <iostream>

class Client
{
private:
	List groceries;
public:
	Client();
	void main_loop();
	void print_menu() const;
	bool in_range(const int value, const int min, const int max) const;
	void exit() const;
};

#endif
