/*********************************************************************
** Program Filename: Barbarian.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/28/2015
** Description:      Subclass of Creature class
** Input:            None
** Output:           See Creature class
********************************************************************/

#ifndef SSHILLYER_BARBARIAN_HPP
#define SSHILLYER_BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian : public Creature
{
public:
  Barbarian();
  std::string get_name();
};

#endif
