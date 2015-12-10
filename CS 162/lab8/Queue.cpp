/*********************************************************************
** Program Filename: Queue.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             11/13/2015
** Description:      Simple implmentation of a Queue using a circular,
**                   doubly-linked format. Empty nodes contain -1. Only
**                   holds postiive (non-negative and non-zero) integers
** Input:            Int Values can be passed in to add_back()
** Output:           Can print its front node, all nodes, or build a
**                   queue.
********************************************************************/


#include "Queue.hpp"


/*********************************************************************
** Function:         Queue::Queue()
** Description:      Constructor. Creates a node flagged as available
** Parameters:       None
** Pre-Conditions:   .
** Post-Conditions:  QueueNode will be set to -1 and front/back will
**                   point to the node. ITs next/front will point to self
********************************************************************/
Queue::Queue()
{
  // make front and back point the first empty node, set empty flag, next/prev points to itself
  back = new QueueNode;
  back->value = -1;
  back->next = back;
  back->prev = back;
  front = back;
}


/*********************************************************************
** Function:         Queue::~Queue()
** Description:      Destructor. Frees all memory allocated for ADT
** Parameters:       None allowed.
** Pre-Conditions:   Called during destruction
** Post-Conditions:  Memory all freed.
********************************************************************/
Queue::~Queue()
{
  // unlink the circle so we know when we've reached end
  QueueNode* last_node = back->prev;
  last_node->next = NULL;

  // Traverse the node using back; garbage follows in wake and deletes
  while (back->next != NULL)
  {
    QueueNode* garbage = back;
    back = back->next;
    delete garbage;
  }
  // Kill last node and clear danglers
  delete last_node;
  back = NULL;
  last_node = NULL;
}


/*********************************************************************
** Function:         void Queue::add_back(int value)
** Description:      Push an int onto back of list and update *back
** Parameters:       integer to push on to back
** Pre-Conditions:   None
** Post-Conditions:  All pointers will be updated and value will be
**                   at the new back of the list (this may be a new
**                   node or just the one that was behind *back)
********************************************************************/
void Queue::add_back(int value)
{
  // Case 1: There is an available node behind the back node
  if (back->prev->value == -1)
  {
    back = back->prev;
    back->value = value;
  }

  // Case 2: There is no empty node behind the back node
  else if (back->prev->value != -1)
  {
    QueueNode* new_back = new QueueNode; // our new node
    QueueNode* old_end = back->prev;     // remember what used to be behind back
    new_back->value = value;             // plug in the value
    new_back->prev = old_end;            // the new back's prev must point where the old back's prev did
    new_back->next = back;               // new back's next needs to point to the prior back
    old_end->next = new_back;            // the prior back->prev needs to poitn to our new back
    back->prev = new_back;               // The back needs to now point to the new back as its prior
    back = new_back;                     // finally move the back pointer to the new relinked node
  }
}


/*********************************************************************
** Function:         int Queue::get_front()
** Description:      Returns the value that's on the front of the Queue
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Returns an int if the node has a positive value,
**                   throws a string exception if front points to an
**                   empty node
********************************************************************/
int Queue::get_front()
{
  if (front->value != -1)
    return front->value;
  else
    throw std::string("Queue is empty!\n");
}


/*********************************************************************
** Function:         void Queue::remove_front()
** Description:      Removes an item from front and moves the front back 1
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Sets the value at current front to -1, updates The
**                   front to the prior node, and throws a string if
**                   front points to empty node
********************************************************************/
void Queue::remove_front()
{
  // Case 1: Front points to a valid value (Queue is not "empty")
  if (front->value != -1)
  {
    front->value = -1; // TODO check lab description if we need to ALSO return the value?
    front = front->prev;
  }

  // Case 2: Front points to an "empty" / "available" node
  else if (front->value == -1)
  {
    throw std::string("Queue is already empty!\n");
  }
}


/*********************************************************************
** Function:         void Queue::traverse()
** Description:      Traverses the circularly linked Queue and prints
**                   the values at each node.
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Prints the value in each node unless it has the
**                   "empty" sentinel value of -1
********************************************************************/
// void Queue::traverse()
// {
//   QueueNode* trav = front;
//   int i = 0;
//   while (trav->prev != front)
//   {
//     if (trav->value != -1)
//     {
//       std::cout << "Element at position " << i << ": " << trav->value << "\n";
//       i++;
//     }
//     trav = trav->prev;
//   }
//   if (trav->value != -1)
//     std::cout << "Element at position " << i << ": " << trav->value << "\n";
// }
