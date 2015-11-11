/*********************************************************************
** Program Filename: List.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/08/2015
** Description:      A List class that allows a user to add and remove
**                   Items, print the list and the prices, etc.
** Input:            User input at terminal to set up the Items
** Output:           Prints list and summary to terminal
********************************************************************/
#ifndef SSHILLYER_LIST_HPP
#define SSHILLYER_LIST_HPP

#include "Item.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

class List
{
private:
  std::vector<Item> items;
  std::vector<UnitType> units;
  /* Private methods */
  void create_unit_types();
  std::string prompt_name() const;
  UnitType prompt_unit_type() const;
  int prompt_number_to_buy() const;
  double prompt_unit_price() const;

public:
  List();
  void print_list();
  bool add_item();
  bool remove_item();
};

#endif
