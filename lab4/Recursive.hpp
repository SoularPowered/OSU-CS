/*********************************************************************
** Program Filename: Recursive.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/15/2015
** Description:      Class for running static recursive functions.
** Input:            Only the arguments required for method calls
** Output:           Returns values depending on which static method is called
********************************************************************/

#ifndef SSHILLYER_RECURSIVE_HPP
#define SSHILLYER_RECURSIVE_HPP

#include <string>
#include <iostream>

class Recursive
{
public:
	Recursive();
	static std::string reverse_string(const std::string str);
	static double sum_array(const double array[], const int elements);
	static int triangle_number(const int n);
};

#endif
