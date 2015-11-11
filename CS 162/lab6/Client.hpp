/*********************************************************************
** Program Filename: Client.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/28/2015
** Description:      A Client class to handle input for StackList and
**                   QueueList class testing purposes
** Input:            User input at terminal to select options
** Output:           Prints values to demonstrate lists
********************************************************************/
#ifndef SSHILLYER_CLIENT_HPP
#define SSHILLYER_CLIENT_HPP

#include "StackList.hpp"
#include "QueueList.hpp"
#include <iostream>
#include <cstddef>

class Client
{
public:
	Client();
	void main_loop();
	void print_menu() const;
	void print_menu_b() const;
	void run_simulation();
	void run_simulation2();
	void stacklist_demo();
	void queuelist_demo();
	bool in_range(const int value, const int min, const int max) const;
	void exit() const;
};

#endif
