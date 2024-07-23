#include "SuperDragon.h"

SuperDragon::SuperDragon() : Dragon() {
  monster_name = "Super Dragon";
  skill_name = "Undying Flame";
  monster_level = 5;
  reset();
}

int SuperDragon::attack(int attack_type, string opponent_type) {
  switch (attack_type) {
    case 1:
      if (opponent_type == "Serbine") {
        return (strength * 1.5);
      } else {
        return strength;
      }
      break;
    case 2:
      if (opponent_type == "Serbine") {
        health = health - ((0.015 * monster_level) * health);
        return strength * 3;
      } else {
        health = health - ((0.015 * monster_level) * health);
        return strength * 2;
      }
      break;
    case 3:
      if (opponent_type == "Serbine") {
        return strength * 2.5;
      } else {
        return strength * 1.8;
      }
      break;
    default:
      return strength;
  }
}

SuperDragon::~SuperDragon() {}