#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "Machine.h"
#include "Monster.h"

using namespace std;
class Player {
 private:
  string user_name;
  Monster** monster_list;
  int current_monster;
  int attack_type;
  int coins;
  int player_level;

 public:
  Player();
  Player(string user_name);

  // Set current monster checks if user input is valid. If valid, it set current
  // monster based on user input
  bool set_monster(string monster_name);
  // Return monster index: Dragon - 0, Titan - 1, Aqua - 2, Serbine -3
  int get_current_monster();
  // Return player level
  int get_player_level();
  // Return the current amount of coins player has
  int get_coins();
  // Return the player name
  string get_player_name();
  // Set new amount of coins
  void set_coins(int new_coins);
  // Set player name
  void set_player_name(string player_name);
  // Set player level
  void set_player_level(int player_level);
  // Get monster list function will return the value of array of pointer to give
  // access to different monster type object
  Monster** get_monster_list();

  // This function return the amount of player damage based on chosen attack
  // type by user and the machine monster type
  int attack(Machine* opponent, int attack_type);
  // This function reduce the player monster health
  void take_attack(int strength);
  // This function increase player level and monster stats and decrease player
  // coins regard to their level.
  void level_up();
  // After each round, the player monsters stat reset to original level (level
  // before the battle)
  void reset();
  // The reward function check if the player win or lose the battle and give
  // respective amount of coins rewards
  int reward(bool win);
  // This function is used to display the player damage based on the chosen
  // monster type to the screen
  void display_attack(int strength);
  ~Player();
};

#endif