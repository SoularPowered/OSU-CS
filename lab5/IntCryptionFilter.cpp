/*********************************************************************
** Program Filename: IntCryptionFilter.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      Simple subclass that encrypts characters from
**                   an istream to an fstream. Decryption not likely
**                   possible as implemented.
** Input:            Input from user upon instantiation for an integer
**                   representing the 'key' for the algorithm
** Output:           Returns an ofstream object with encrytped characters
********************************************************************/
#include "IntCryptionFilter.hpp"


/*********************************************************************
** Function:         IntCryptionFilter()
** Description:      Default constructor. Calls prompt_key() method
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  IntCryptionFilter object will exist with a key set
********************************************************************/
IntCryptionFilter::IntCryptionFilter()
{
	this->key = prompt_key();
}


/*********************************************************************
** Function:         IntCryptionFilter()
** Description:      Alternate constructor. Accepts k as an argument
** Parameters:       integer k, passed on to set the key
** Pre-Conditions:   None
** Post-Conditions:  IntCryptionFilter object will exist with a key set
********************************************************************/
IntCryptionFilter::IntCryptionFilter(int k)
{
	if (k < 0 || k > 25)
	{
		std::cout << "Invalid key passed to constructor.\n";
		prompt_key();
	}
	else
	{
		this->key = k;
	}
}


/*********************************************************************
** Function:         transform()
** Description:      Returns a ch between 0 and 26 for a hard to
**                   crack encryption (simple decryption not possible)
** Parameters:       a char ch to encrypt
** Pre-Conditions:   Ojbect must exist. Called by the do_filter method
** Post-Conditions:  Returns a ch between 0 and 25
********************************************************************/
char IntCryptionFilter::transform(const char ch) const
{
	int offset = 0;
	if (ch >= 'A' && ch <= 'Z')
	{
		offset = 'A';
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		offset = 'a';
	}

	if (offset == 0) // if non-alpha character, return original char
	{
		return ch;
	}
	/* remove the offset, add the key, and mod 26, then add the offset back in
	to get a character in the upper or lowercase alphabetical ASCII sets */
	return ( ( (ch - offset + key) % 26) + offset);
}


/*********************************************************************
** Function:         prompt_key()
** Description:      Prompts user for an integer between MIN_KEY and
**                   MAX_KEY and returns the value
** Parameters:       None
** Pre-Conditions:   IntCryptionFilter object must be in process of
**                   instantiating. Could be called again to change.
** Post-Conditions:  objects key value is set
********************************************************************/
int IntCryptionFilter::prompt_key()
{
	const int MIN_KEY = 0, MAX_KEY = 25;
	int key = MIN_KEY - 1;
	do {
		std::cout << "Enter an integer to use as key (between " << MIN_KEY << " - " << MAX_KEY << ")\n >";
		std::cin >> key;
	} while(key < MIN_KEY || key > MAX_KEY);

	return key;
}
