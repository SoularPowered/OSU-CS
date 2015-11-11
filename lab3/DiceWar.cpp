/*********************************************************************
** Program Filename: DiceWar.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      A Class provided an interface to play a game of
**                   war played with Dice.
** Input:           Prompts user for number of sides per die and number
**                  of rounds, and if each player's die is Loaded
** Output:          Plays rounds of the game and reports the winner.
********************************************************************/
#include "DiceWar.hpp"

/*********************************************************************
** Function:         DiceWar()
** Description:      Constructor
** Parameters:       None
** Pre-Conditions:   DiceWar must be instantiated by calling code
** Post-Conditions:  DiceWar will be initialized with dummy values.
********************************************************************/
DiceWar::DiceWar()
{
  std::cout << "Welcome to DiceWar - The Game\n";
  number_rounds = 1;
  for (int i = 0; i < 2; i++)
    player_score[i] = 0;
  dice_sides = 6;
}


/*********************************************************************
** Function:         ~DiceWar()
** Description:      Deconstructor
** Parameters:       None
** Pre-Conditions:   DiceWar object must fall out of scope
** Post-Conditions:  Dynamically allocated Die will be freed from memory
********************************************************************/
DiceWar::~DiceWar()
{
  for (int i = 0; i < 2; i++)
  {
    delete player_dice[i];
  }
}


/*********************************************************************
** Function:         start_new_game()
** Description:      Initializes the game with user input and runs through
**                   all game logic sequentially
** Parameters:       None
** Pre-Conditions:   DiceWar must exist
** Post-Conditions:  A game will be created and played and results
**                   printed to screen
********************************************************************/
void DiceWar::start_new_game()
{
  /* Reset score for both players */
  for (int i = 0; i < 2; i++)
  {
    player_score[i] = 0;
  }

  /* Initialize the game with user input settings */
  dice_sides = prompt_die_sides();
  number_rounds = prompt_num_rounds();

  /* Prompt if each player's die is loaded and use appropriate die */
  if (prompt_if_loaded("Player 1"))
  {
    player_dice[0] = new LoadedDie(dice_sides);
  }
  else
  {
    player_dice[0] = new Die(dice_sides);
  }

  if (prompt_if_loaded("Player 2"))
  {
    player_dice[1] = new LoadedDie(dice_sides);
  }
  else
  {
    player_dice[1] = new Die(dice_sides);
  }

  /* Play each round */
  for (int round = 1; round <= number_rounds; round++)
  {
    play_round(round);
  }
  game_over(check_winner());
}


/*********************************************************************
** Function:         prompt_die_sides()
** Description:      Prompts for and validates input for number of die sides
** Parameters:       None
** Pre-Conditions:   DiceWar obj must exist
** Post-Conditions:  returns an int in range MIN_SIDES <= return val <= MAX_SIDES
********************************************************************/
int DiceWar::prompt_die_sides()
{
  int num_die_sides = 0;
  const int MIN_SIDES = 4, MAX_SIDES = 20000;
  do
  {
    std::cout << "How many sides should the dice have? (Between " << MIN_SIDES << " and " << MAX_SIDES << " )\n>";
    std::cin >> num_die_sides;
  } while(num_die_sides < MIN_SIDES || num_die_sides > MAX_SIDES);

  return num_die_sides;
}


/*********************************************************************
** Function:         prompt_num_rounds()
** Description:      Prompts for and validates input for number of rounds
** Parameters:       None
** Pre-Conditions:   DiceWar obj must exist
** Post-Conditions:  Returns int in range MIN_ROUNDS <= return val <= MAX_ROUNDS
********************************************************************/
int DiceWar::prompt_num_rounds()
{
  int num_rounds = 0;
  const int   MIN_ROUNDS = 1,
              MAX_ROUNDS = 20000;
  do
  {
    std::cout << "How many rounds should be played? (Between " << MIN_ROUNDS << " and " << MAX_ROUNDS << " )\n>";
    std::cin >> num_rounds;
  } while(num_rounds < MIN_ROUNDS || num_rounds > MAX_ROUNDS);

  return num_rounds;
}


/*********************************************************************
** Function:         prompt_if_loaded()
** Description:      Asks user if each player is using a loaded die or not
** Parameters:       A string to print so user knows which player is being
**                   set up with a Die
** Pre-Conditions:   DiceWar obj must exist
** Post-Conditions:  Returns true if user says yes, false if user says no
********************************************************************/
bool DiceWar::prompt_if_loaded(std::string player_name)
{
  const bool IS_LOADED = true;
  char input;
  std::cout << "Is " << player_name << " using a loaded die? (Y or N)\n>";
  std::cin.get(input);
  while (toupper(input) != 'Y' && toupper(input) != 'N')
  {
    std::cout << "Enter 'Y' for YES, 'N' for NO.\n>";
    std::cin.get(input);
  }
  if (toupper(input) == 'Y')
    return IS_LOADED;
  else if (toupper(input) == 'N')
    return !IS_LOADED;
}


/*********************************************************************
** Function:         play_round()
** Description:      Rolls die for each player and prints results, updates
**                   the score
** Parameters:       An integer for the current round number
** Pre-Conditions:   Game must be properly initialized through play_round
** Post-Conditions:  Player score will be updated and round's results
**                   printed to screen.
********************************************************************/
void DiceWar::play_round(int round)
{
  int player_one_roll = player_dice[0]->roll();
  int player_two_roll = player_dice[1]->roll();

  std::cout << "Round " << round << "\n";
  std::cout << "Player 1 rolls: " << player_one_roll << ".\n";
  std::cout << "Player 2 rolls: " << player_two_roll << ".\n";

  if (player_one_roll > player_two_roll)
  {
    update_player_score(0, 1); // increase player 1's score
  }
  else if (player_two_roll > player_one_roll)
  {
    update_player_score(1,1); // increase player 2's score
  }
  // IF == nobody gets a point ("draw")
}


/*********************************************************************
** Function:         update_player_score()
** Description:      Increments a players score
** Parameters:       int representing the player's index and int for
**                   the number of points to increase the score by
** Pre-Conditions:   Called by play_round()
** Post-Conditions:  Increments player_score[index] per called values
**
********************************************************************/
void DiceWar::update_player_score(int player_index, int points)
{
  player_score[player_index] += points;
}


/*********************************************************************
** Function:         game_over()
** Description:      Recaps the scores and reports who the winner is
** Parameters:       The index of the winner of the game
** Pre-Conditions:   All rounds must be played and check_winner must
**                   be called as the argument to determine the real winner
** Post-Conditions:  Results printed to screen.
********************************************************************/
void DiceWar::game_over(int winner)
{
  std::cout << "After " << number_rounds << " vicious rounds of DiceWar, we have tallied the scores...\n";
  std::cout << "Player One scored " << player_score[0] << " points!\n";
  std::cout << "Player Two scored " << player_score[1] << " points!\n";

  std::cout << "The victor is... ";
  if (winner == 0)
  {
    std::cout << "Player One!\n";
  }
  else if (winner == 1)
  {
    std::cout << "Player Two!\n";
  }
  else if (winner == 2)
  {
    std::cout << "undecided! We have a draw!";
  }
}


/*********************************************************************
** Function:         check_winner()
** Description:      Returns the index of the player that won
** Parameters:       None
** Pre-Conditions:   All rounds must be played
** Post-Conditions:  Returns 0 if player 1 won, 1 if player 2 won, and
**                   2 if a draw.
********************************************************************/
int DiceWar::check_winner()
{
  int winner_index = 2; // if a tie, we will return 2 to game_over()
  if (player_score[0] > player_score[1])
  {
    return 0;
  }
  else if (player_score[1] > player_score[0])
  {
    return 1;
  }
  else
    return winner_index;
}

/*********************************************************************
** Function:         quit()
** Description:      Prints message to player after quitting.
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Prints a message and game ends.
********************************************************************/
void DiceWar::quit()
{
  std::cout << "Thanks for playing!\n";
}
