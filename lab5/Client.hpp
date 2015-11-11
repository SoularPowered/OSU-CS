/*********************************************************************
** Program Filename: Client.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/08/2015
** Description:      A Client class to handle FileFilter and subclasses.
**                   Prints the menu and gets choices and generally
**                   handles main program logic.
** Input:            User input at keyboard
** Output:           Creates files per user input using variosu filters.
**                   Prints menu to screen.
********************************************************************/
#ifndef SSHILLYER_CLIENT_HPP
#define SSHILLYER_CLIENT_HPP

#include "CopyFilter.hpp"
#include "FileFilter.hpp"
#include "ToUpperFilter.hpp"
#include "IntCryptionFilter.hpp"
#include <iostream>
#include <string>

class Client
{
private:
	void copy_file() const;
	void uppercase_file() const;
	void encrypt_file() const;
	void allfilters_file() const;
	std::string prompt_filename(std::string) const;
	bool in_range(const int value, const int min, const int max) const;
public:
	Client();
	void main_loop() const;
	void print_menu() const;
	void exit() const;
};

#endif
