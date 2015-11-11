/*********************************************************************
** Program Filename: List.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/08/2015
** Description:      A List class that allows a user to add and remove
**                   Items, print the list and the prices, etc.
** Input:            User input at terminal to set up the Items
** Output:           Prints list and summary to terminal
********************************************************************/
#include "List.hpp"


/*********************************************************************
** Function:         List()
** Description:      Constructor calls create_unit_types to build the
**                   predifined unit_types. Instantiates list so that
**                   other functions can be called
** Parameters:       None
** Pre-Conditions:   List must be instantiated
** Post-Conditions:  List object will exist; vector<UnitTypes> units
**                   filled with data
********************************************************************/
List::List()
{
	create_unit_types();
}


/*********************************************************************
** Function:         print_list()
** Description:      Prints the string representation of all items in list
**                   with nice formatting and 2-decimal precision.
** Parameters:       None.
** Pre-Conditions:   List must be instantiated. Prints an empty list of no
**                   items in list.
** Post-Conditions:  Displays each Item name, quantity, unit_type, unit_price,
**                   extended_price, total price of all items, and count of items
********************************************************************/
void List::print_list()
{
	/* Initialize counter and setup bars for easy printing */
	double total_price = 0;
	const std::string LONG_BAR = std::string(75, '=');
	const std::string SHORT_BAR = std::string(30, '=');

	/* Print the formatted items and calculate the extended price */
	std::cout << "\n\n" << LONG_BAR << "\nYour Grocery List\n" << LONG_BAR << "\n";
	for (unsigned int i = 0; i < items.size(); i++)
	{
		std::string item_string = items[i].to_string();
		std::cout << item_string << "\n";
		total_price += items[i].extended_price();
	}

	/* Print footer of the report */
	std::cout << LONG_BAR;
	std::cout << "\nTotal Items: " << items.size() << "\n";
	std::cout << "\nTotal Cost: $";
	std::cout << std::setw(17)<< std::right << std::fixed << std::showpoint << std::setprecision(2);
	std::cout << total_price << "\n" << SHORT_BAR << "\n\n";
}


/*********************************************************************
** Function:         add_item()
** Description:      Add an item to the List
** Parameters:       none
** Pre-Conditions:   List must exist.
** Post-Conditions:  Item will be added to items vector and returns true
**                   or returns false if item aleady exists in list
********************************************************************/
bool List::add_item()
{
	const bool ITEM_ADDED = true;

	std::string item_name = prompt_name();
	UnitType unit_type = prompt_unit_type();
	int number_to_buy = prompt_number_to_buy();
	double unit_price = prompt_unit_price();

	/* Build the item and push it to the vector if it doesn't already exist */
	Item temp_item = Item(item_name, unit_type, number_to_buy, unit_price);

	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i] == temp_item)
		{
			std::cout << item_name << " already in list!\n";
			return !ITEM_ADDED;
		}
	}

	items.push_back(temp_item);
	std::cout << item_name << " added to the list.\n";
	return ITEM_ADDED; // returns true
}


/*********************************************************************
** Function:         remove_item()
** Description:      Remove an item from the List
** Parameters:       none
** Pre-Conditions:   List must exist; item cannot be removed if it's not
**                   in the list
** Post-Conditions:  Item will be removed from items vector if it exists
**                   Returns true if successful, false otherwsie
********************************************************************/
bool List::remove_item()
{
	std::string item_name;
	const bool ITEM_REMOVED = true;
	std::vector<Item>::iterator list_iter; // so I can call .erase()

	std::cout << "What is the name of the item to remove? \n>";
	std::getline(std::cin, item_name);
	Item comp_item = Item(item_name, UnitType("", ""), 1, 1);

	for (list_iter = items.begin(); list_iter != items.end(); list_iter++)
	{
		if (*list_iter == comp_item)
		{
			items.erase(list_iter);
			std::cout << item_name << " removed from the list.\n";
			return ITEM_REMOVED;
		}
	}
	std::cout << item_name << " was not on the list!\n";
	return !ITEM_REMOVED; // returns false - no item was found to remove.
}


/*********************************************************************
** Function:         create_unit_types()
** Description:      Hardcodes the unit types into the vector of units
** Parameters:       None
** Pre-Conditions:   List constructor must call
** Post-Conditions:  Vector units will be populated with the UnitTypes
**                   in the method definition
********************************************************************/
void List::create_unit_types()
{
	units.push_back(UnitType("box", "es"));
	units.push_back(UnitType("ounce", "s"));
	units.push_back(UnitType("pound", "s"));
	units.push_back(UnitType("can", "s"));
	units.push_back(UnitType("dozen", "s"));
	units.push_back(UnitType("cup", "s"));
	units.push_back(UnitType("bottle", "s"));
	units.push_back(UnitType("bag", "s"));
	units.push_back(UnitType("gallon", "s"));
	units.push_back(UnitType("quart", "s"));
	units.push_back(UnitType("count", ""));
}


/*********************************************************************
** Function:         prompt_name()
** Description:      Prompts for name and returns the string value
** Parameters:       None
** Pre-Conditions:   add_item() must be called
** Post-Conditions:  returns string of at least one character
********************************************************************/
std::string List::prompt_name() const
{
	std::string item_name = "";
	do {
		std::cout << "Name of item: \n>";
		std::getline(std::cin, item_name);
		if (item_name == "")
		{
			std::cout << "Please enter at least one character.\n";
		}
	} while(item_name == "");

	return item_name;
}


/*********************************************************************
** Function:         prompt_unit_type()
** Description:      Prompts for unit_type and returns the selected type
** Parameters:       None
** Pre-Conditions:   add_item() must be called
** Post-Conditions:  returns a UnitType
********************************************************************/
UnitType List::prompt_unit_type()  const
{
	/* Print the unit options by index */
	for (unsigned unit_index = 0; unit_index < units.size(); unit_index++)
	{
		std::cout << unit_index << ": " << units[unit_index].to_plural() << "\t";
		if (unit_index % 5 == 5)
			std::cout << "\n";
	}

	int		unit_choice = -1,
			min_index = 0,
			max_index = static_cast<int>(units.size() - 1);

	while ((unit_choice < min_index) || (unit_choice > max_index))
	{
		std::cout << "\nPlease enter a unit type from menu. Valid options are " << min_index << " to " << max_index << ").\n>";
		std::cin >> unit_choice;
	}

	UnitType temp = units[unit_choice];
	return temp;

}


/*********************************************************************
** Function:         prompt_number_to_buy()
** Description:      Prompts for number_to_buy and returns int value
** Parameters:       None
** Pre-Conditions:   add_item() must be called
** Post-Conditions:  returns int between MIN_TO_BUY and MAX_TO_BUY
********************************************************************/
int List::prompt_number_to_buy() const
{
	const int MIN_TO_BUY = 1, MAX_TO_BUY = 2000000;
	int number_to_buy = -1;
	while ((number_to_buy < MIN_TO_BUY) || (number_to_buy > MAX_TO_BUY))
	{
		std::cout << "Please enter a quantity to buy (between " << MIN_TO_BUY << " and " << MAX_TO_BUY << ").\n>";
		std::cin >> number_to_buy;
	}
	return number_to_buy;
}


/*********************************************************************
** Function:         prompt_unit_price()
** Description:      Prompts for unit_price and returns double value
** Parameters:       None
** Pre-Conditions:   add_item() must be called
** Post-Conditions:  returns double between MIN_PRICE and MAX_PRICE
********************************************************************/
double List::prompt_unit_price() const
{
	double unit_price = -1;
	const double MIN_PRICE = 0.01, MAX_PRICE = 2000000;
	while ((unit_price < MIN_PRICE) || (unit_price > MAX_PRICE))
	{
		std::cout << std::fixed << std::setprecision(0);
		std::cout << "Please enter a unit price (between " << MIN_PRICE << " and " << MAX_PRICE << ").\n>";
		std::cin >> unit_price;
	}
	return unit_price;
}
