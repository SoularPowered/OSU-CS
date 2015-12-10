/*********************************************************************
** Program Filename: Client.cpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/28/2015
** Description:      A Client class to handle input for Combat simulator.
**                   Prints the menu and gets choices and generally
**                   handles main program logic.
** Input:            User input at terminal to select options
** Output:           Instantaites the Combat class which generates
**                   two log files (readable on unix and windows)
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
** Post-Conditions:  Calls other methods as appropriate
********************************************************************/
void Client::main_loop()
{
	const int first_choice = 1, last_choice = 4;
	int menu_choice = 0;

	while (menu_choice != last_choice)
	{
		do
		{
			print_menu();
			std::cin >> menu_choice;
		} while (!in_range(menu_choice, 1, last_choice));
		std::cin.ignore(100, '\n');
		switch (menu_choice)
		{
		case 1:
			run_simulation();
			break;
		case 2:
			run_simulation(0, 1, 5);
			break;
		case 3:
			custom_simulation();
			break;
		case last_choice:
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
	std::cout << "1: Run All Simulations\n";
	std::cout << "2: Run Short Simulation\n";
	std::cout << "3: Run Custom Simulation\n";
	std::cout << "4: Quit\n";
	std::cout << ">> ";
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
** Function:         run_simulation()
** Description:      Runs a simulation of every class versus every
**                   other class of Creature.
** Parameters:       Can take two ints to control loops and an int
**                   to control # of samples. All have default valus
** Pre-Conditions:   None
** Post-Conditions:  Prints the combat on terminal and logs results
********************************************************************/
void Client::run_simulation(const int FIRST, const int LAST, const int SAMPLES)
{
	std::string bar(60, '@');   // For indicating begin and end of each pairing easily
	std::string filename = "auto";

	// Use nested loops to match up all subclasses
	int sim_count = 0;      // Counts the number of simulations; used for logging purposes
	for (int i = FIRST; i < LAST; i++)
	{
		for (int j = i; j < LAST; j++)  // j = i to avoid repeating any pairings
		{
			sim_count++;
			Creature* attackers[] = { new Barbarian, new BlueMen, new Goblin, new ReptilePeople, new TheShadow };
			Creature* defenders[] = { new Barbarian, new BlueMen, new Goblin, new ReptilePeople, new TheShadow };

			int win_count[2] = { 0, 0 }; // keep track of winner
			for (int k = 0; k < SAMPLES; k++)
			{
				std::cout << "Combat Sim for this pairing: # " << k+1 << "\n";
				std::cout << bar << '\n';

				Combat sim(attackers[i], defenders[j]);
				// resolve_combat() returns 0 if attacker won, 1 if defender won; increases the win counter
				win_count[sim.resolve_combat()]++;
				attackers[i]->reset();
				defenders[j]->reset();
			}

			// Report statistics and log resuls
			double win_rate = report_statistics(attackers[i]->get_name(), defenders[j]->get_name(), win_count, SAMPLES);
			log_combat(attackers[i]->get_name(), defenders[j]->get_name(), win_count, win_rate, sim_count, filename);

			// Free memory allocations
			for (int i = 0; i < 5; i++)
			{
				delete attackers[i];
				delete defenders[i];
			}
		}
	}
}


/*********************************************************************
** Function:         custom_simulation()
** Description:      Runs a simulation of a specific class versus every
**                   another specific class of Creature.
** Parameters:       None. All input gathered as subroutines
** Pre-Conditions:   None
** Post-Conditions:  Prints combat and logs results to filename
********************************************************************/
void Client::custom_simulation()
{
	std::string bar(60, '@');   // For indicating begin and end of each pairing easily
	Creature* attackers[] = { new Barbarian, new BlueMen, new Goblin, new ReptilePeople, new TheShadow };
	Creature* defenders[] = { new Barbarian, new BlueMen, new Goblin, new ReptilePeople, new TheShadow };

	// Get user input
	int atk_i = prompt_creature("attacking creature");
	int def_i = prompt_creature("defending creature");
	int num_samples = prompt_samplesize();
	std::string filename = prompt_filename();

	int sim_count = 0;            // Counts the number of simulations; used for logging purposes
	int win_count[2] = { 0, 0 };  // keep track of winner

	for (sim_count = 0; sim_count < num_samples; sim_count++)
	{
		std::cout << "Combat Sim for this pairing: # " << sim_count+1 << "\n";
		std::cout << bar << '\n';

		Combat sim(attackers[atk_i], defenders[def_i]);
		win_count[sim.resolve_combat()]++; // winner's index is incremented
		attackers[atk_i]->reset();
		defenders[def_i]->reset();
	}

	// Report statistics and log results
	double win_rate = report_statistics(attackers[atk_i]->get_name(), defenders[def_i]->get_name(), win_count, num_samples);
	log_combat(attackers[atk_i]->get_name(), defenders[def_i]->get_name(), win_count, win_rate, sim_count, filename);

	// Free memory allocations
	for (int i = 0; i < 5; i++)
	{
		delete attackers[i];
		delete defenders[i];
	}

}


/*********************************************************************
** Function:         report_statistics()
** Description:      Reports results and returns the winrate of index 0
**                   creature
** Parameters:       2 strings for the creature names, array of size 2
**                   with num of wins, number of samples/simulations run
** Pre-Conditions:   Input values must exist; best to call after a simulation
** Post-Conditions:  Prints results to screen and returns the winrate
********************************************************************/
double Client::report_statistics(std::string creature_a_name, std::string creature_b_name, int win_count[2], int samples)
{
	std::string bar(60, '=');
	double win_rate = (static_cast<double>(win_count[0]) / samples);
	std::cout << "Attacking " << creature_a_name << " won: " << win_count[0] << " times (";
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	std::cout << win_rate * 100 << "%).\n";
	std::cout << "Defending " << creature_b_name << " won: " << win_count[1] << " times.(";
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	std::cout << (1-win_rate) * 100 << "%).\n" << bar << "\n";
}


/*********************************************************************
** Function:         log_combat()
** Description:      Logs the results of combat
** Parameters:       Two creatures names (strings), array of scores,
**                   the winrate (double), and number of samples (int)
** Pre-Conditions:   run_simulation() will have to have run already
**                   to have necessary data to pass in
** Post-Conditions:  Two files will be created, one for windows and one
**                   for posix based systems
********************************************************************/
void Client::log_combat(std::string creature_a_name, std::string creature_b_name,
	int scores[], double win_rate, int sample_num, std::string filename)
{
	// Make two files, one for unix and one for windows platforms. '\r\n' on windows for linebreaks
	std::string u_file_name = filename + "_combat_log_nix.txt";      // without carriage returns for unix
	std::string win_file_name = filename + "_combat_log_win.txt";    // with carriage returns for windows
	std::ofstream log_file(u_file_name.c_str(), std::ios::app);

	log_file << "=======================================================\n";
	log_file << "Simulation " << sample_num << "\n";
	log_file << creature_a_name << " vs. " << creature_b_name << "\n";
	log_file << std::setw(15) << creature_a_name << " won: " << std::setw(6) << scores[0] << "\t";
	log_file << "Win Rate: " << win_rate*100 << "%\n";
	log_file << std::setw(15) << creature_b_name << " won: " << std::setw(6) << scores[1] << "\t";
	log_file << "Win Rate: " << (1-win_rate)*100 << "%\n";
	log_file << "=======================================================\n";
	log_file.close();

	std::ofstream win_log_file(win_file_name.c_str(), std::ios::app);

	win_log_file << "=======================================================\r\n";
	win_log_file << "Simulation " << sample_num << "\r\n";
	win_log_file << creature_a_name << " vs. " << creature_b_name << "\r\n";
	win_log_file << std::setw(15) << creature_a_name << " won: " << std::setw(6) << scores[0] << "\t";
	win_log_file << "Win Rate: " << win_rate*100 << "%\r\n";
	win_log_file << std::setw(15) << creature_b_name << " won: " << std::setw(6) << scores[1] << "\t";
	win_log_file << "Win Rate: " << (1-win_rate)*100 << "%\r\n";
	win_log_file << "=======================================================\n";
	win_log_file.close();
}


/*********************************************************************
** Function:         prompt_creature()
** Description:      Prompts user for the type of creature to use
** Parameters:       A string to use as a label
** Pre-Conditions:   None
** Post-Conditions:  Returns an index for the type of creature to use
********************************************************************/
int Client::prompt_creature(std::string label)
{
	const int MAX_TYPES = 5;

	std::cout << "Pick " << label << " type:\n";
	std::string type_names[] = { "Barbarian", "Blue Men", "Goblin", "Reptile People", "The Shadow"};

	for (int i = 0; i < MAX_TYPES; i++)
	{
		std::cout << i+1 << ": " << type_names[i] << "\n";
	}
	int input = -1;
	do
	{
		std::cout << "You must select an option from 1 to " << MAX_TYPES <<"\n>";
		std::cin >> input;
	} while(!in_range(input, 1, MAX_TYPES));

	input--; // shift down to match with index

	return input;
}


/*********************************************************************
** Function:         prompt_samplesize()
** Description:      Prompts user for the number of samples to use
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Returns users integer input as a response
********************************************************************/
int Client::prompt_samplesize()
{
	const int MIN = 1, MAX = 5000;
	int input = -1;
	do
	{
		std::cout << "Enter number of simulations to run: (" << MIN << " - " << MAX << ")\n>";
		std::cin >> input;
	} while(!in_range(input, MIN, MAX));

	return input;
}


/*********************************************************************
** Function:         prompt_filename()
** Description:      Prompts user for the filename prefix
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Returns users string input as a response
********************************************************************/
std::string Client::prompt_filename()
{
	std::string filename;

	do
	{
			std::cout << "Enter a prefix for the combat log filename (no spaces/invalid characters!):\n>";
			std::cin >> filename;
	} while(filename.length() == 0);
	return filename;
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
	srand(time(0));
	Client client;
	return 0;
}
