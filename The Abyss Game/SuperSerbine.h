#ifndef SUPERSERBINE_H
#define SUPERSERBINE_H

#include <string>

#include "Serbine.h"

using namespace std;

class SuperSerbine : public Serbine {
 public:
  // constructor
  SuperSerbine();
  // Added type 3 attack type
  int attack(int attack_type, string opponent_type);
  ~SuperSerbine();
};

#endif