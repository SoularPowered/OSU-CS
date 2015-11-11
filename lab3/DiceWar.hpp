/*********************************************************************
** Program Filename: DiceWar.hpp		[HEADER]
** Author:           Shawn Hillyer
** Date:             10/12/2015
** Description:      A Class provided an interface to play a game of
**                   war played with Dice.
** Input:            Prompts user for number of sides per die and number
**                   of rounds, and if each player's die is Loaded
** Output:           Plays rounds of the game and reports the winner.
********************************************************************/

#ifndef SSHILLYER_DICEWAR_HPP
#define SSHILLYER_DICEWAR_HPP

#include "Die.hpp"
#include "LoadedDie.hpp"
#include <string>
#include <iostream>

class DiceWar
{
private:
  /* Data */
  Die* player_dice[2];
  int number_rounds;
  int player_score[2];
  int dice_sides;

  /* Private methods */
  int prompt_die_sides();
  int prompt_num_rounds();
  bool prompt_if_loaded(std::string player_name);
  void play_round(int round);
  void update_player_score(int player_index, int points);
  void game_over(int winner);
  int check_winner();
public:
  /* Constructor(s) / Destructor(s) */
  DiceWar();
  ~DiceWar();

  /* Public methods */
  void start_new_game();
  void quit();
};
#endif
