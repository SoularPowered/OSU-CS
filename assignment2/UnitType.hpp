/*********************************************************************
** Program Filename: UnitType.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/08/2015
** Description:      Simple class to define a types of units for a grocery Item
** Input:            None
** Output:           Can return string representation of base_name or
**                   base_name+plural_suffix
********************************************************************/

#ifndef SSHILLYER_UNITTYPE_HPP
#define SSHILLYER_UNITTYPE_HPP

#include <string>

class UnitType
{
private:
	std::string base_name;
	std::string plural_suffix;
public:
	/* In-lined methods because very little code for each method */
	/* Constructor */
	UnitType(const std::string name ="", const std::string sfx="")
	{
		base_name = name;
		plural_suffix = sfx;
	}
	/* returns base_name value */
	std::string to_singular() const
	{
		return base_name;
	}
	/* returns base_name + plural_suffix */
	std::string to_plural() const
	{
		return base_name + plural_suffix;
	}
};

#endif
