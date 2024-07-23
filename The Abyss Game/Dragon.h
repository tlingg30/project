#ifndef DRAGON_H
#define DRAGON_H

#include "Monster.h"

class Dragon : public Monster {
 private:
 public:
  // constructor for player monster
  Dragon();
  // constructor for machine monster
  Dragon(int game_level);

  // Attack function thats unique to each type of monster
  virtual int attack(int attack_type, string opponent_type);
  // Refill function use when player level up
  void reFill();
  // Reset the stat to initial level after each battle
  void reset();
  // Reset the stat for game loading
  void reset_for_load(int player_level);
  ~Dragon();
};

#endif