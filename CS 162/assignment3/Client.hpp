/*********************************************************************
** Program Filename: Client.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/08/2015
** Date:             10/28/2015
** Description:      A Client class to handle input for Combat simulator.
**                   Prints the menu and gets choices and generally
**                   handles main program logic.
** Input:            User input at terminal to select options
** Output:           Instantaites the Combat class which generates
**                   two log files (readable on unix and windows)
********************************************************************/
#ifndef SSHILLYER_CLIENT_HPP
#define SSHILLYER_CLIENT_HPP

#include "Combat.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Creature.hpp"
#include "Die.hpp"
#include "Goblin.hpp"
#include "ReptilePeople.hpp"
#include "TheShadow.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

class Client
{
public:
	Client();
	void main_loop();
	void print_menu() const;
	bool in_range(const int value, const int min, const int max) const;
	void exit() const;
	double report_statistics(const std::string, const std::string, int [2], const int); // Refactored out method
	void log_combat(std::string creature_a_name, std::string creature_b_name, int scores[], double win_rate, int sample_num, std::string);
	void run_simulation(const int = 0, const int = 5, const int = 100);
	void custom_simulation();
	int prompt_creature(std::string label);
	int prompt_samplesize();
	std::string prompt_filename();
};

#endif
