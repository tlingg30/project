#ifndef AQUA_H
#define AQUA_H

#include "Monster.h"

class Aqua : public Monster {
 private:
 public:
  // Constructor for player monster
  Aqua();
  // constructor for machine monster
  Aqua(int game_level);

  // Refill function use when player level up
  void reFill();
  // Reset the stat to initial level after each battle
  void reset();
  // Reset the stat for game loading
  void reset_for_load(int player_level);
  // Attack function thats unique to each type of monster
  virtual int attack(int attack_type, string opponent_type);
  ~Aqua();
};

#endif