/*********************************************************************
** Program Filename: TestSuite.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             11/27/2015
** Description:      A collection of functions to test and compare
**                   runtime performance.
** Input:            User input at keyboard
** Output:           Prints results to screen and logs to file
********************************************************************/
#ifndef SSHILLYER_TESTSUITE_HPP
#define SSHILLYER_TESTSUITE_HPP

#include "Logger.hpp"
#include <iostream>

class TestSuite
{
public:
  static long rfactorial(int n);
  static long factorialHelper(int n, int result);
  static long factorial(int n);
  static long fib_rec(int n);
  static long fib_iter(int n);
  static void test_fib();
  static void test_fact();
};

#endif
