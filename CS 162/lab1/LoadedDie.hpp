/*********************************************************************
** Program Filename:	LoadedDie.hpp
** Author:				Shawn Hillyer
** Date:				09/24/2015
** Description:			Header file for LoadedDie. Emulates a die
**	that has been "loaded" to produce higher rolls than a fair die
** Input:				N/A
** Output:				N/A
********************************************************************/

#ifndef SSHILLYER_LOADEDDIE_HPP
#define SSHILLYER_LOADEDDIE_HPP

class LoadedDie
{
private:
	/* Data members */
	int num_sides;
	double* value_weights;	// stores weights for each possible roll

	/* Private function(s) */
	bool load_worked(int);
	void load_die(double);
	void set_num_sides(int);

public:
	/* Constructors & destructors */
	LoadedDie(int sides = 6);
	~LoadedDie();

	/* Overloaded operator(s) */
	LoadedDie(LoadedDie &obj);

	/* Callable functions */
	int roll();
};

#endif
