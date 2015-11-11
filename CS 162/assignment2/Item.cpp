/*********************************************************************
** Program Filename: Item.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/08/2015
** Description:      An Item class that allows a clients to create an
**                   Item with a name, qty to buy, price, and calculate
**                   the extended price for the item. Can return a string
**                   representing all of this information.
** Input:            User input at terminal to set up the Items
** Output:           Prints list and summary to terminal
********************************************************************/
#include "Item.hpp"


/*********************************************************************
** Function:         Item()
** Description:      Constructor passes arguments to set_ functions
** Parameters:       string for name, UnitType for unit, int and doulbe
**                   for num_to_buy and price
** Pre-Conditions:   Called during instantiation.
** Post-Conditions:  Item will be initialized with valid data.
********************************************************************/
Item::Item(const std::string n, const UnitType units, const int num_to_buy, const double price)
{
  set_name(n);
  set_unit_type(units);
  set_number_to_buy(num_to_buy);
  set_unit_price(price);
}


/*********************************************************************
** Function:         set_name()
** Description:      Sets the name for the item
** Parameters:       string for name
** Pre-Conditions:   None
** Post-Conditions:  name will be set to n
********************************************************************/
void Item::set_name(const std::string item_name)
{
  name = item_name;
}


/*********************************************************************
** Function:         set_unit_type()
** Description:      Sets the unit type for Item
** Parametersconst :       UnitType for the units
** Pre-Conditions:   None
** Post-Conditions:  unit_type will be set to units
********************************************************************/
void Item::set_unit_type(const UnitType units)
{
  unit_type = units;
}


/*********************************************************************
** Function:         set_number_to_buy()
** Description:      Sets the qty to buy to at least 1
** Parameters:       An int for num_to_buy
** Pre-Conditions:   None
** Post-Conditions:  number_to_buy will be set to num_to_buy or 1
********************************************************************/
void Item::set_number_to_buy(const int num_to_buy)
{
  if (num_to_buy < 1)
  {
    number_to_buy = 1;
  }
  else
  {
    number_to_buy = num_to_buy;
  }
}


/*********************************************************************
** Function:         set_unit_price()
** Description:      Sets the unit_price
** Parameters:       double for price
** Pre-Conditions:   None
** Post-Conditions:  unit_price will be set to price or 1.00 otherwise
********************************************************************/
void Item::set_unit_price(const double price)
{
  if (price <= 0)
  {
    unit_price = 1.00;
  }
  else
  {
    unit_price = price;
  }
}


/*********************************************************************
** Function:         to_string()
** Description:      Returns a strin representation for the Item
** Parameters:       None
** Pre-Conditions:   Item must be fully initialized
** Post-Conditions:  REturns a string representation of the Item
********************************************************************/
std::string Item::to_string() const
{
	std::ostringstream os;

	os << std::left << std::setw(15) << name;
	os << std::right << std::setw(5) << number_to_buy << " ";
  /* This if-else handles singular vs pluralization of unit type */
	if (number_to_buy > 1)
		os << unit_type.to_plural();
	else
		os << unit_type.to_singular();
	os << "\t @ " << "$" << std::fixed << std::showpoint << std::setprecision(2) << unit_price << " ea.";
	os << "\tExt. Price: $" << extended_price();

	std::string str = os.str(); // extract string from the os object and store in str
	return str;
}


/*********************************************************************
** Function:         extended_price()
** Description:      Returns the extended price for an Item
** Parameters:       None
** Pre-Conditions:   Item must be fully instantiated
** Post-Conditions:  Returns a double result of number_to_buy * unit_price
********************************************************************/
double Item::extended_price() const
{
  return number_to_buy * unit_price;
}


/*********************************************************************
** Function:         operator==()
** Description:      Overloaded comparison operator==.
** Parameters:       Implicitly accepts an Item object with == is used
**                   to compare two Items. Uses name as comparison
** Pre-Conditions:   Items must exist to call the comparison on
** Post-Conditions:  Returns true of objects are considered equal, false
**                   otherwise.
********************************************************************/
bool Item::operator==(const Item &rhs)  const
{
  if (this->name == rhs.name)
  {
    return true;
  }
  else
  {
  return false;
  }
}
