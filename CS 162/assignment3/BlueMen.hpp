/*********************************************************************
** Program Filename: BlueMen.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/28/2015
** Description:      Subclass of Creature class
** Input:            None
** Output:           See Creature class
********************************************************************/

#ifndef SSHILLYER_BLUEMEN_HPP
#define SSHILLYER_BLUEMEN_HPP

#include "Creature.hpp"

class BlueMen : public Creature
{
private:
public:
  BlueMen();
  std::string get_name();
};

#endif
