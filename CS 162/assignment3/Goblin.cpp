/*********************************************************************
** Program Filename: Goblin.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/28/2015
** Description:      Subclass of Creature class
** Input:            None
** Output:           See Creature class
********************************************************************/

#include "Goblin.hpp"


/*********************************************************************
** Function:         Goblin()
** Description:      Constructor
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Goblin fully initialized
********************************************************************/
Goblin::Goblin()
{
	this->type_name = "Goblin";

  // 2d6 attack
  this->attack_dice_sides = 6;
  this->attack_dice_count = 2;

  // 1d6 defense
  this->defense_dice_sides = 6;
  this->defense_dice_count = 1;

  this->armor = 3;
  this->strength = 8;
  this->default_strength = 8;
}


/*********************************************************************
** Function:         attack_roll()
** Description:      Overrides base class attack roll
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  IF goblin rolls a 12, then turns on special_active
**                   (Turned off by combat class)
********************************************************************/
int Goblin::attack_roll()
{
  this->special_active = false;
  int roll = Creature::attack_roll();
  if (roll == 12)
  {
    special_active = true;
  }
  return roll;
}


/*********************************************************************
** Function:         get_name()
** Description:      Returns name
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Returns name
********************************************************************/
std::string Goblin::get_name()
{
	return this->type_name;
}
