#include "SuperAqua.h"

SuperAqua::SuperAqua() : Aqua() {
  monster_name = "Super Aqua";
  skill_name = "Call of sea";
  monster_level = 5;
  reset();
}

int SuperAqua::attack(int attack_type, string opponent_type) {
  switch (attack_type) {
    case 1:
      if (opponent_type == "Dragon") {
        return (strength * 1.5);
      } else {
        return strength;
      }
      break;
    case 2:
      if (opponent_type == "Dragon") {
        health = health - ((0.015 * monster_level) * health);
        return strength * 3;
      } else {
        health = health - ((0.015 * monster_level) * health);
        return strength * 2;
      }
      break;
    case 3:
      if (opponent_type == "Dragon") {
        return strength * 2.5;
      } else {
        return strength * 1.8;
      }
      break;
    default:
      return strength;
  }
}

SuperAqua::~SuperAqua() {}