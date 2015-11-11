/*********************************************************************
** Program Filename: .hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      Simple subclass that uppercases characters from
**                   an istream to an fstream.
** Input:            See base class
** Output:           Returns an ofstream object with uppercased characters
********************************************************************/
#ifndef SSHILLYER_TOUPPERFILTER_HPP
#define SSHILLYER_TOUPPERFILTER_HPP

#include "FileFilter.hpp"
#include <cctype>

class ToUpperFilter : public FileFilter
{
public:
	char transform(const char ch) const;
};

#endif
