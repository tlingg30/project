#include "Dragon.h"
Dragon::Dragon() : Monster(210, 15, 30) { monster_name = "Dragon"; }

Dragon::Dragon(int game_level)
    : Monster(400 + ((game_level - 1) * 200), 10 + ((game_level - 1) * 10)) {}

int Dragon::attack(int attack_type, string opponent_type) {
  switch (attack_type) {
    case 1:
      if (opponent_type == "Serbine") {
        return strength * 1.5;
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
    default:
      return strength;
  }
}

void Dragon::reFill() {
  set_strength(get_strength() + 15);
  set_health(get_health() + 45);
  set_critical_attack(get_critical_attack() + 15);
  monster_level++;
}

void Dragon::reset() {
  set_strength(15 + ((monster_level - 1) * 15));
  set_health(210 + ((monster_level - 1) * 45));
  set_critical_attack(30 + ((monster_level - 1) * 15));
}

void Dragon::reset_for_load(int player_level) {
  set_strength(15 + ((player_level - 1) * 15));
  set_health(210 + ((player_level - 1) * 45));
  set_critical_attack(30 + ((player_level - 1) * 15));
}

Dragon::~Dragon() {}
