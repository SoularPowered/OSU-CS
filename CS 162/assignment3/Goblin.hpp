/*********************************************************************
** Program Filename: Goblin.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/28/2015
** Description:      Subclass of Creature class
** Input:            None
** Output:           See Creature class
********************************************************************/

#ifndef SSHILLYER_GOBLIN_HPP
#define SSHILLYER_GOBLIN_HPP

#include "Creature.hpp"
#include <cstdlib>

class Goblin : public Creature
{
private:
public:
  Goblin();
  int attack_roll(); // override virtual function
  std::string get_name();
};

#endif
