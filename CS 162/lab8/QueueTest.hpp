/*********************************************************************
** Program Filename: QueueTest.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             11/13/2015
** Description:      Simple testing class.
** Input:            None
** Output:           Can prompt a user for a valid value for purposes
**                   of the Queue implementation included with this file.
********************************************************************/

#ifndef SSHILLYER_QUEUETEST_HPP
#define SSHILLYER_QUEUETEST_HPP

class QueueTest
{
private:
public:
  static int prompt_value()
  {
    int input = -1;
    do
    {
      std::cout << "Type a positive integer to add to Queue (0 is neither positive nor negative and thus invalid):\n> ";
      std::cin >> input;
    } while(input <= 0);
    return input;
  }
};

#endif
