#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>

#include "Aqua.h"
#include "Dragon.h"
#include "Monster.h"
#include "Serbine.h"
#include "SuperAqua.h"
#include "SuperDragon.h"
#include "SuperSerbine.h"
#include "SuperTitan.h"
#include "Titan.h"

using namespace std;
class Machine {
 private:
  Monster** machine_monster;

 public:
  Machine();
  // static int get_level();
  //  need for attack function in Monster class
  // static string get_monster_type();
  // Since the machine can only have 1 monster at a time therefore the
  // monster_type and game_level variable is set to static
  static string monster_type;
  static int game_level;

  // Return the pointer to the monster object of Machine class
  Monster* get_monster();

  // level up function increase game level, meaning increase the strength of the
  // machine monster in the next battle
  void level_up();
  // Return machine monster strength
  int get_strength();
  // random machine's monster (index) drawn before player going to each battle
  // in main.cpp
  void set_monster(int index);
  // This function used when the machine monster take damage from player and
  // reduce machine health accordingly
  void take_attack(int strength);
  // Set new game level
  void set_game_level(int _game_level);
  // Display the damage the player take (display the machine monster object
  // strength)
  void display_attack();

  ~Machine();
};

#endif