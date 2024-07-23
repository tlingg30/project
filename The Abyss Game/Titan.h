#ifndef TITAN_H
#define TITAN_H

#include "Monster.h"

class Titan : public Monster {
 private:
 public:
  // constructor for player monster
  Titan();
  // constructor for machine monster
  Titan(int game_level);

  // Attack function thats unique to each type of monster
  virtual int attack(int attack_type, string opponent_type);
  // Refill function use when player level up
  void reFill();
  // Reset the stat to initial level after each battle
  void reset();
  // Reset the stat for game loading
  void reset_for_load(int player_level);
  ~Titan();
};

#endif