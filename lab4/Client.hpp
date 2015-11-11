/*********************************************************************
** Program Filename: Client.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/15/2015
** Description:      A Client class to handle a recurision function testing.
**                   Handles the menu and logic branching.
** Input:            User input at terminal to select options/enter vals
** Output:           Prints results of the function calls and a menu
**                   for user to select options
********************************************************************/
#ifndef SSHILLYER_CLIENT_HPP
#define SSHILLYER_CLIENT_HPP

#include "Recursive.hpp"
#include <iostream>
#include <vector>

class Client
{
public:
	Client();
	void main_loop();
	void print_menu() const;
	bool in_range(const int value, const int min, const int max) const;
	std::string prompt_string() const;
	double* prompt_array(int&) const;
	double* prompt_array_alt(int&) const;
	int prompt_triangle() const;
	void exit() const;
};

#endif
