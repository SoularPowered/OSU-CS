/*********************************************************************
** Program Filename: Barbarian.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/28/2015
** Description:      Subclass of Creature class
** Input:            None
** Output:           See Creature class
********************************************************************/

#include "Barbarian.hpp"


/*********************************************************************
** Function:         Barbarian()
** Description:      Constructor
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Barbarian fully initialized
********************************************************************/
Barbarian::Barbarian()
{
	this->type_name = "Barbarian";

  // 2d6 attack
  this->attack_dice_sides = 6;
  this->attack_dice_count = 2;

  // 2d6 defense
  this->defense_dice_sides = 6;
  this->defense_dice_count = 2;

  this->armor = 0;
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
std::string Barbarian::get_name()
{
	return this->type_name;
}
