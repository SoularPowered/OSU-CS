/*********************************************************************
** Program Filename: FileFilter.cpp		[IMPLEMENTATION]
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
#include "FileFilter.hpp"


/*********************************************************************
** Function:         do_filter()
** Description:      Copies contents from in to out one char at a time
** Parameters:       existing ifstream and ostream objects
** Pre-Conditions:   the fstream objects must already exist
** Post-Conditions:  the ofstream object will have the same characters
**                   as the ifstream object prior to the func call
********************************************************************/
void FileFilter::do_filter(std::ifstream &in, std::ofstream &out) const
{
	char ch; // read a character
	char trans_ch; // the character to be written after transformation
	in.get(ch);
	/* read characters until the read operation fails (typically EOF) */
	while (!in.fail())
	{
		trans_ch = transform(ch);
		out.put(trans_ch);
		in.get(ch);
	}
}
