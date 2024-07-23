#ifndef SUPERDRAGON_H
#define SUPERDRAGON_H

#include <string>

#include "Dragon.h"

using namespace std;

class SuperDragon : public Dragon {
 public:
  // constructor
  SuperDragon();
  // Added type 3 attack type
  int attack(int attack_type, string opponent_type);
  ~SuperDragon();
};
#endif