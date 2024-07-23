#ifndef SUPERTITAN_H
#define SUPERTITAN_H

#include <string>

#include "Titan.h"

using namespace std;

class SuperTitan : public Titan {
 public:
  // constructor
  SuperTitan();
  // Added type 3 attack type
  int attack(int attack_type, string opponent_type);
  ~SuperTitan();
};

#endif