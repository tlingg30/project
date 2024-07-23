#include "SuperTitan.h"

SuperTitan::SuperTitan() : Titan() {
  monster_name = "Super Titan";
  skill_name = "Devastating Crumbling";
  monster_level = 5;
  reset();
}

int SuperTitan::attack(int attack_type, string opponent_type) {
  switch (attack_type) {
    case 1:
      if (opponent_type == "Aqua") {
        return (strength * 1.5);
      } else {
        return strength;
      }
      break;
    case 2:
      if (opponent_type == "Aqua") {
        health = health - ((0.015 * monster_level) * health);
        return strength * 3;
      } else {
        health = health - ((0.015 * monster_level) * health);
        return strength * 2;
      }
      break;
    case 3:
      if (opponent_type == "Aqua") {
        return strength * 2.5;
      } else {
        return strength * 1.8;
      }
      break;
    default:
      return strength;
  }
}

SuperTitan::~SuperTitan() {}