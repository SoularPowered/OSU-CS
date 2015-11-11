/*********************************************************************
** Program Filename: Item.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/08/2015
** Description:      An Item class that allows a clients to create an
**                   Item with a name, qty to buy, price, and calculate
**                   the extended price for the item. Can return a string
**                   representing all of this information.
** Input:            User input at terminal to set up the Items
** Output:           Prints list and summary to terminal
********************************************************************/
#ifndef SSHILLYER_ITEM_HPP
#define SSHILLYER_ITEM_HPP

#include "UnitType.hpp"
#include <string>
#include <sstream>
#include <iomanip>
class Item
{
private:
  std::string name;
  UnitType unit_type;
  int number_to_buy;
  double unit_price;
public:
  Item(const std::string n, const UnitType units, const int num_to_buy, const double price);
  void set_name(const std::string n);
  void set_unit_type(const UnitType units);
  void set_number_to_buy(const int num_to_buy);
  void set_unit_price(const double price);
  std::string to_string() const;
  double extended_price()  const;
  bool operator==(const Item &rhs) const;
};

#endif
