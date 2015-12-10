/*********************************************************************
** Program Filename: QueueNode.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             11/13/2015
** Description:      Simple structure to hold value and a pointer to
**                   next and previous nodes
** Input:            Can hold integer values and pointer to other QueueNodes
** Output:           None explicit; POD to use in DE Queue
********************************************************************/

#ifndef SSHILLYER_QUEUENODE_HPP
#define SSHILLYER_QUEUENODE_HPP

#include <cstddef>

struct QueueNode
{
  int value; // -1 means empty
  QueueNode* next;
  QueueNode* prev;
};

#endif
