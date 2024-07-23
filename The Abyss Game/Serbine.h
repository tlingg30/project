#ifndef SERBINE_H
#define SERBINE_H

#include "Monster.h"

class Serbine : public Monster {
 private:
 public:
  // Constructor for player monster
  Serbine();
  // construcor for machine monster
  Serbine(int game_level);

  // Refill function use when player level up
  void reFill();
  // Reset the stat to initial level after each battle
  void reset();
  // Reset the stat for game loading
  void reset_for_load(int player_level);
  // Attack function thats unique to each type of monster
  virtual int attack(int attack_type, string opponent_type);
  ~Serbine();
};

#endif