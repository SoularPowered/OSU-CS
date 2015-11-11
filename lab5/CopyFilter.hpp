/*********************************************************************
** Program Filename: CopyFilter.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      Simple File Filter class to be used to convert
**                   a file. The transformation can be overridden by
**                   classes which inherit from CopyFilter.
** Input:            do_filter requires an existing ifstream and ofstream
**                   object to read and write from/to respectively
** Output:           Alters a ofstream object to have the same contents
**                   as an istream object.
********************************************************************/
#ifndef SSHILLYER_CopyFilter_HPP
#define SSHILLYER_CopyFilter_HPP

#include "FileFilter.hpp"

#include <fstream>

class CopyFilter : public FileFilter
{
public:
	virtual char transform(const char ch) const;
};

#endif
