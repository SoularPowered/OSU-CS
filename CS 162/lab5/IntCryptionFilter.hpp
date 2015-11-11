/*********************************************************************
** Program Filename: .hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      Simple subclass that encrypts characters from
**                   an istream to an fstream. Decryption not likely
**                   possible as implemented.
** Input:            Input from user upon instantiation for an integer
**                   representing the 'key' for the algorithm
** Output:           Returns an ofstream object with encrytped characters
********************************************************************/
#ifndef SSHILLYER_INTCRYPTIONFILTER_HPP
#define SSHILLYER_INTCRYPTIONFILTER_HPP

#include "FileFilter.hpp"
#include <iostream>

class IntCryptionFilter : public FileFilter
{
private:
	int key;
	virtual char transform(const char ch) const;
public:
	IntCryptionFilter();
	IntCryptionFilter(int k);
	int prompt_key();
};

#endif
