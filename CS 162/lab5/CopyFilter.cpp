/*********************************************************************
** Program Filename: CopyFilter.cpp		[IMPLEMENTATION]
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
#include "CopyFilter.hpp"

/*********************************************************************
** Function:         transform()
** Description:      Virtual function - can be overridden by subclasses.
**                   Returns same char as argument ch
** Parameters:       a char ch to be transformed
** Pre-Conditions:   CopyFilter needs to be isntantiated
** Post-Conditions:  returns the ch that was passed
********************************************************************/
char CopyFilter::transform(const char ch) const
{
	return ch;
}
