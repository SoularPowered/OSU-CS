/*********************************************************************
** Program Filename: Client.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      A Client class to handle a Dice game using the
**                   terminal for input and output. Handles main
**                   game loop and main menu to start a game of DiceWar
** Input:            A menu choice from user
** Output:           Will launch game or quit the program.
********************************************************************/
#ifndef SSHILLYER_CLIENT_HPP
#define SSHILLYER_CLIENT_HPP

#include "DiceWar.hpp"
#include <iostream>

class Client
{
private:
	DiceWar game;
public:
	Client();
	void main_loop();
	void print_menu();
	bool in_range(const int value, const int min, const int max);
	void exit();
};

#endif
