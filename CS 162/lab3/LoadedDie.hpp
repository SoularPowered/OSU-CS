/*********************************************************************
** Program Filename: LoadedDie.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      Modified code from another student for a LoadedDie
**                   converted to inherit from Die class of mine
** Input:            None or one int for num of sides
** Output:           Can call rand to get an int from 1 to num_sides
********************************************************************/

#ifndef LOADED_H
#define LOADED_H

#include "Die.hpp"

class LoadedDie : public Die
{
	public:
		LoadedDie(int);
		virtual int roll();
};
#endif
