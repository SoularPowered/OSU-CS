/*********************************************************************
** Program Filename: ReptilePeople.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/28/2015
** Description:      Subclass of Creature class
** Input:            None
** Output:           See Creature class
********************************************************************/

#include "ReptilePeople.hpp"


/*********************************************************************
** Function:         ReptilePeople()
** Description:      Constructor
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  ReptilePeople fully initialized
********************************************************************/
ReptilePeople::ReptilePeople()
{
	this->type_name = "Reptile People";

  // 3d6 attack
  this->attack_dice_sides = 6;
  this->attack_dice_count = 3;

  // 1d6 defense
  this->defense_dice_sides = 6;
  this->defense_dice_count = 1;

  this->armor = 7;
  this->strength = 18;
  this->default_strength = 18;
}


/*********************************************************************
** Function:         get_name()
** Description:      Returns name
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Returns name
********************************************************************/
std::string ReptilePeople::get_name()
{
	return this->type_name;
}
