/*********************************************************************
** Program Filename: FileFilter.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      Simple File Filter class to be used to convert
**                   contents of a file. THis is an abstract class;
**                   classes which inherit from FileFilter must overridden
**                   .transform()
** Input:            do_filter requires an existing ifstream and ofstream
**                   object to read and write from/to respectively
**                   To use this class, a derived class must override
**                   and be instantiated.
** Output:           Alters a ofstream object to have the contents
**                   of the ifstream object, only transformed
********************************************************************/
#ifndef SSHILLYER_FILEFILTER_HPP
#define SSHILLYER_FILEFILTER_HPP

#include <fstream>

class FileFilter
{
public:
	virtual char transform(const char ch) const = 0;
	void do_filter(std::ifstream &in, std::ofstream &out) const;
};

#endif
