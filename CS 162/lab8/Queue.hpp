/*********************************************************************
** Program Filename: Queue.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             11/13/2015
** Description:      Simple implmentation of a Queue using a circular,
**                   doubly-linked format. Empty nodes contain -1. Only
**                   holds postiive (non-negative and non-zero) integers
** Input:            Int Values can be passed in to add_back()
** Output:           Can print its front node, all nodes, or build a
**                   queue.
********************************************************************/

#ifndef SSHILLYER_QUEUE_HPP
#define SSHILLYER_QUEUE_HPP

#include "QueueNode.hpp"
#include <cstddef>
#include <iostream>

class Queue
{
private:
  QueueNode* front;
  QueueNode* back;

public:
  Queue();
  ~Queue();
  void add_back(int);
  int get_front();
  void remove_front();
  // void traverse(); // used for testing purposes
};

#endif
