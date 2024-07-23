#ifndef SUPERAQUA_H
#define SUPERAQUA_H

#include <string>

#include "Aqua.h"

using namespace std;

class SuperAqua : public Aqua {
 public:
  // constructor
  SuperAqua();
  // Added type 3 attack type
  int attack(int attack_type, string opponent_type);
  ~SuperAqua();
};

#endif