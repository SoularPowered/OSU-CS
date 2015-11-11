/*********************************************************************
** Program Filename: Client.cpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/08/2015
** Description:      A Client class to handle FileFilter and subclasses.
**                   Prints the menu and gets choices and generally
**                   handles main program logic.
** Input:            User input at keyboard
** Output:           Creates files per user input using variosu filters.
**                   Prints menu to screen.
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
	main_loop();
}


/*********************************************************************
** Function:         main_loop()
** Description:      Prompts for and validates user choice for next action
** Parameters:       None
** Pre-Conditions:   Client must exist
** Post-Conditions:  Program will proceed to apply various file filters
**                   until user decides to quit.
********************************************************************/
void Client::main_loop() const
{
  const int FIRST_CHOICE = 1, LAST_CHOICE = 5;
  int menu_choice = 0;

  while (menu_choice != LAST_CHOICE)
  {
    do
    {
      print_menu();
      std::cin >> menu_choice;
    } while (!in_range(menu_choice, FIRST_CHOICE, LAST_CHOICE));
	std::cin.ignore(100, '\n');
    switch (menu_choice)
    {
    case 1:
		  copy_file();
      break;
    case 2:
			uppercase_file();
      break;
    case 3:
			encrypt_file();
			break;
		case 4:
			allfilters_file();
		  break;
    case LAST_CHOICE:
      exit();
      break;
    }
  }
}


/*********************************************************************
** Function:         print_menu()
** Description:      Prints main menu
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Menu will be displayed on terminal
********************************************************************/
void Client::print_menu() const
{
  std::cout << "\nWhat would you like to do?\n";
	std::cout << "1: Copy a file\n";
	std::cout << "2: Uppercase a file\n";
	std::cout << "3: Encrypt a file (To decrypt, enter 26 minus original key)\n";
	std::cout << "4: Perform all actions on file\n";
	std::cout << "5: Quit\n";
	std::cout << "> ";
}


/*********************************************************************
** Function:         in_range()
** Description:      Checks if int 'value' is in range [min,max] inclusive
** Parameters:       int value, in min, and int max
** Pre-Conditions:   Value to check and a range must be passed in
** Post-Conditions:  Returns true if min <= value <= max, false otherwise
********************************************************************/
bool Client::in_range(const int value, const int min, const int max) const
{
	if (value >= min && value <= max)
		return true;
	else
		return false;
}


/*********************************************************************
** Function:         copy_file()
** Description:      Makes a copy of a file per user input
** Parameters:       None
** Pre-Conditions:   Client must exist. Valid input file must exist in same
**                   Folder as the executable
** Post-Conditions:  If user provides valid input, copy of file with
**                   filename per user input
********************************************************************/
void Client::copy_file() const
{
	/* Get string names and open files */
	std::string in_filename = prompt_filename("input");
	std::string copy_filename = prompt_filename("copied output");
	std::ifstream in_file(in_filename.c_str());
	std::ofstream copy_file(copy_filename.c_str());

	/* Run filters */
	FileFilter* p_copy_filter = new CopyFilter;
	p_copy_filter->do_filter(in_file, copy_file);
	in_file.close();
	copy_file.close();
}


/*********************************************************************
** Function:         uppercase_file()
** Description:      Makes an uppercased copy of a file per user input
** Parameters:       None
** Pre-Conditions:   Client must exist. Valid input file must exist in same
**                   Folder as the executable
** Post-Conditions:  If user provides valid input, copy of uppercased file with
**                   filename per user input
********************************************************************/
void Client::uppercase_file() const
{
	/* Get string names and open files */
	std::string in_filename = prompt_filename("input");
	std::string upper_filename = prompt_filename("uppercased output");
	std::ifstream in_file(in_filename.c_str());
	std::ofstream upper_file(upper_filename.c_str());

	/* Run filters */
	FileFilter* p_upper_filter = new ToUpperFilter;
	p_upper_filter->do_filter(in_file, upper_file);
	in_file.close();
	upper_file.close();
}


/*********************************************************************
** Function:         encrypt_file()
** Description:      Makes an encrypted copy of a file per user input
** Parameters:       None
** Pre-Conditions:   Client must exist. Valid input file must exist in same
**                   Folder as the executable
** Post-Conditions:  If user provides valid input, copy of encrypted file with
**                   filename per user input
********************************************************************/
void Client::encrypt_file() const
{
	/* Get string names and open files */
	std::string in_filename = prompt_filename("input");
	std::string encrypt_filename = prompt_filename("encrypted output");
	std::ifstream in_file(in_filename.c_str());
	std::ofstream encrypt_file(encrypt_filename.c_str());

	/* Run filters */
	FileFilter* p_encrypt_filter = new IntCryptionFilter;
	p_encrypt_filter->do_filter(in_file, encrypt_file);
	in_file.close();
	encrypt_file.close();
}


/*********************************************************************
** Function:         allfilters_file()
** Description:      Runs all filters (copy, uppercase, encrypt) to
**                   demonstrate use of polymorphism to call same method
**                   on various subclasses pointed to by a pointer-to-base
** Parameters:       None
** Pre-Conditions:   Client must exist. Valid input file must exist in same
**                   Folder as the executable
** Post-Conditions:  If user provides valid input, straight copy, encrypted
**                   file, and uppercased file with filenames per user input
********************************************************************/
void Client::allfilters_file() const
{
	const int NUM_FILTERS = 3; // to control # of loops and array sizes

	/* Setup variables to hold filenames and array of filestream objs */
	std::string in_filename = prompt_filename("input");
	std::string out_file_labels[NUM_FILTERS] = {"copied output", "uppercased output", "encrypted output"};
	std::string out_filename[NUM_FILTERS];
	std::ofstream out_files[NUM_FILTERS];

	/* Prompt for filename and open the input and then the output files */
	std::ifstream in_file(in_filename.c_str());
	for (int i = 0; i < NUM_FILTERS; i++)
	{
		out_filename[i] = prompt_filename(out_file_labels[i]);
		out_files[i].open(out_filename[i].c_str());
	}

	FileFilter* p_filters[NUM_FILTERS]; // array of pointers to base class FileFilter
	p_filters[0] = new CopyFilter();
	p_filters[1] = new ToUpperFilter();
	p_filters[2] = new IntCryptionFilter();

	/* Process each file and immediately close */
	for (int i = 0; i < NUM_FILTERS; i++)
	{
		p_filters[i]->do_filter(in_file, out_files[i]);
		out_files[i].close();
		std::cout << "File " << out_filename[i] << " written succesfully.\n";

		/* rewind file and clear flags */
		in_file.clear();
		in_file.seekg(0L, std::ios::beg);
	}
	in_file.close();
	// TODO Add error checking on each .open call and print message if it fails and return from function
	return;
}


/*********************************************************************
** Function:         prompt_filename()
** Description:      Prompts user for a filename longer than 0 characters
**                   and returns string to caller
** Parameters:       takes a label to label the input for user
** Pre-Conditions:   pass in a string or string-literal
** Post-Conditions:  Returns a string > .length() == 0
********************************************************************/
std::string Client::prompt_filename(std::string label) const
{
	std::string filename ="";
	while (filename.length() == 0)
	{
		std::cout << "Enter a filename for " << label << " file.\n>";
		std::cin >> filename;
	}
	std::cin.ignore(100, '\n');
	return filename;
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
