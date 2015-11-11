/*********************************************************************
** Program Filename: .cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      Simple subclass that uppercases characters from
**                   an istream to an fstream.
** Input:            See base class
** Output:           Returns an ofstream object with uppercased characters
********************************************************************/
#include "ToUpperFilter.hpp"

/*********************************************************************
** Function:         transform()
** Description:      returns uppercased letters
** Parameters:       a char ch to uppercase
** Pre-Conditions:   None
** Post-Conditions:  Uppercase letter returned
********************************************************************/
char ToUpperFilter::transform(const char ch) const
{
	return toupper(ch);
}
