/*********************************************************************
** Program Filename: BlueMen.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/28/2015
** Description:      Subclass of Creature class
** Input:            None
** Output:           See Creature class
********************************************************************/

#include "BlueMen.hpp"


/*********************************************************************
** Function:         BlueMen()
** Description:      Constructor
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  BlueMen fully initialized
********************************************************************/
BlueMen::BlueMen()
{
	this->type_name = "Blue Men";

  // 2d10 attack
  this->attack_dice_sides = 10;
  this->attack_dice_count = 2;

  // 3d6 defense
  this->defense_dice_sides = 6;
  this->defense_dice_count = 3;

  this->armor = 3;
  this->strength = 12;
  this->default_strength = 12;
}


/*********************************************************************
** Function:         get_name()
** Description:      Returns name
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Returns name
********************************************************************/
std::string BlueMen::get_name()
{
	return this->type_name;
}
