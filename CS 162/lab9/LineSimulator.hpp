/*********************************************************************
** Program Filename: LineSimulator.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             11/20/2015
** Description:      A class to simulate simplistic queue models
** Input:            Requres a label, number of lines, number of serve_customers
**                   and number of ticks to generate new customers for
** Output:           Calling run_simulation() will run the simulation
**                   based on the input values.
** Note:             Does not "reset" itself; instantiate a new
**                   object to run multiple simulations
********************************************************************/
#ifndef SSHILLYER_LINESIMULATOR_HPP
#define SSHILLYER_LINESIMULATOR_HPP

#include "Person.hpp"
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>

class LineSimulator
{
private:
  // Private Data
  std::string label;
  int num_lines;
  int num_servers;
  int time_tick;
  int new_customers_ticks;
  int total_wait_time;
  int total_customers;
  std::vector<std::queue<Person> > cust_queue;

  // Private methods
  void tick();
  void populate_line();
  int calculate_wait_time(const int index) const;
  int count_customers() const;
  void serve_customers();
  int generate_customers() const;
  void print_status() const;

public:
  // Public Methods
  LineSimulator(const std::string label, const int num_lines, const int num_servers, const int new_customers_ticks);
  void run_simulation();
};
#endif
