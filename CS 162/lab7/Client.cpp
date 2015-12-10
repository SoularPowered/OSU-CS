/*********************************************************************
** Program Filename: Client.cpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             11/06/2015
** Description:      A Client class to handle user input and program
**                   output for a SearchSort object
** Input:            User input at terminal to select options
** Output:           Prints values to demonstrate searching/sorting
********************************************************************/
#include "Client.hpp"


/*********************************************************************
** Function:         Client()
** Description:      Instantiate the client and call main_loop()
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  main_loop() will be called and Client will exist
********************************************************************/
Client::Client()
{
	// Load menu file
	std::string main_menu_file = "main.menu";
	this->main_menu.load_menu_file(main_menu_file);

	// Make SearchSort objects - encapsulated arrays
	// data.push_back(SearchSort("random_early.txt"));
	// data.push_back(SearchSort("random_middle.txt"));
	// data.push_back(SearchSort("random_end.txt"));

	load_files();

	// Start main loop
	main_loop();
}


/*********************************************************************
** Function:         main_loop()
** Description:      Prompts for and validates user choice for next action
** Parameters:       None
** Pre-Conditions:   Client must exist
** Post-Conditions:  Calls other methods as appropriate
********************************************************************/
void Client::main_loop()
{

	int menu_choice = 0;

	do
	{
		menu_choice = this->main_menu.prompt_user();
		std::cin.ignore(100, '\n');

		switch (menu_choice)
		{
		case 1:
			perform_linear_search();
			break;
		case 2:
			perform_sort();
			break;
		case 3:
		  perform_binary_search();
			break;
		}
	} while (menu_choice != this->main_menu.get_quit_value());
	exit();
}


/*********************************************************************
** Function:         perform_linear_search()
** Description:      Prompts user for a key and searches for value
**                   using binary linear algorithm
** Parameters:       None
** Pre-Conditions:   Client must have instantiated its data vector
** Post-Conditions:  Reports if value was found in any of the input files
********************************************************************/
void Client::perform_linear_search()
{
	int key = prompt_search_key();

	for (int i = 0; i < data.size(); i++)
	{
		std::cout << "Linear search for value " << key << "in " << data[i].get_filename() << "\n";
		int index = data[i].linear_search(key);
		std::cout << "Values: " << data[i].to_string() << "\n";
		if (index == -1)
			std::cout << key << " not found in array.\n";
		else
			std::cout << key << " found at index: " << index << "\n";
		std::cout << std::endl;
	}
}


/*********************************************************************
** Function:         perform_binary_search()
** Description:      Prompts user for a key and searches for value
**                   using binary search algorithm
** Parameters:       None
** Pre-Conditions:   Client must have initialized its data vector
** Post-Conditions:  Reports if value was found in any of the input files
********************************************************************/
void Client::perform_binary_search()
{
	std::string sorted_filename;
	std::cout << "Filename of sorted values to conduct binary search on.\n";
	std::cout << "('sorted_values.txt' is example file)\n> ";
	std::cin >> sorted_filename;

	SearchSort sorted_data(sorted_filename);

	int key = prompt_search_key();

	std::cout << "Binary search for value " << key << " in " << sorted_data.get_filename() << "\n";
	int index = sorted_data.binary_search(key);

	std::cout << "Values: " << sorted_data.to_string() << "\n";
	if (index == -1)
		std::cout << key << " not found in array.\n";
	else
		std::cout << key << " found at index: " << index << "\n";
	std::cout << std::endl;
}


/*********************************************************************
** Function:         perform_sort()
** Description:      Sorts the arrays in the Client's data vector
** Parameters:       None
** Pre-Conditions:   Client must have initialized its data vector
** Post-Conditions:  Arrays sorted and file created with sorted arrays
********************************************************************/
void Client::perform_sort()
{
	std::string out_filename;
	std::cout << "Filename to write results to:\n> ";
	std::cin >> out_filename;

	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i].get_filename() << " values BEFORE sorting:\n" << data[i].to_string() << "\n";

		data[i].selection_sort();

		std::cout << data[i].get_filename() << " values AFTER sort:\n" << data[i].to_string() << "\n";
		data[i].write_file(out_filename);
	}
}


/*********************************************************************
** Function:         load_files()
** Description:      Prompts user for filenames to open for processing
**                   and loads them into the data vector
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Returns an integer to caller.
********************************************************************/
void Client::load_files()
{
	std::string file_name;
	std::cout << "Enter file names to process linear search and sorting on. You can enter as many as you'd like.\n";
	std::cout << "Type \"DONE\" to stop entering filenames.\n> ";
	do
	{
		std::getline(std::cin, file_name);
		if (file_name != "DONE")
			data.push_back(SearchSort(file_name));
	} while(file_name != "DONE");
}


/*********************************************************************
** Function:         prompt_search_key()
** Description:      Prompts user for an integer to search for
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Returns an integer to caller.
********************************************************************/
int Client::prompt_search_key()
{
	int search_key;
	std::cout << "Enter an integer to search for:\n> ";
	std::cin >> search_key;
	return search_key;
}


/*********************************************************************
** Function:         exit()
** Description:      Executes any code prior to quitting the main loop
** Parameters:       none
** Pre-Conditions:   Client must exist
** Post-Conditions:  Client should stop executing code; drop into main()
********************************************************************/
void Client::exit() const
{
	std::cout << "Exiting program.\n\n";
}


/*********************************************************************
** Function:         main()
** Description:      Entry point for program
** Parameters:       Uses none
** Pre-Conditions:   None
** Post-Conditions:  Program runs
********************************************************************/
int main(int argc, char** argv)
{
	Client client;
	return 0;
}
