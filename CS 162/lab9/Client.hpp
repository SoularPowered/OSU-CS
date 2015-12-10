/*********************************************************************
** Program Filename: Client.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             11/13/2015
** Description:      A Client class to handle user input and program
**                   output
** Input:            User input at terminal to select options
** Output:           Responds to user iput appropriately
********************************************************************/
#ifndef SSHILLYER_CLIENT_HPP
#define SSHILLYER_CLIENT_HPP

#include "Menu.hpp"
#include "Person.hpp"
#include "LineSimulator.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

class Client
{
private:
	Menu main_menu;

public:
	Client();
	void main_loop();
	bool in_range(const int, const int, const int) const;
	void exit() const;
};

#endif
