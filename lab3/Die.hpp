/*********************************************************************
** Program Filename:	Die.hpp
** Author:				Shawn Hillyer
** Date:				09/24/2015
** Description:			Header file for Die class
** Input:				N/A
** Output:				N/A
********************************************************************/

#ifndef SSHILLYER_DIE_HPP
#define SSHILLYER_DIE_HPP

class Die
{
protected:
	/* Data members */
	int num_sides;

	/* Private function(s) */
	void set_num_sides(int);

public:
	/* Constructor(s) */
	Die(int sides = 6);

	/* Callable functions */
	virtual int roll();
};

#endif
