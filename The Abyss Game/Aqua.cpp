#include "Aqua.h"

Aqua::Aqua() : Monster(160, 25, 40) { monster_name = "Aqua"; }

Aqua::Aqua(int game_level)
    : Monster(400 + ((game_level - 1) * 200), 10 + ((game_level - 1) * 10)) {}

void Aqua::reFill() {
  set_strength(get_strength() + 25);
  set_health(get_health() + 35);
  set_critical_attack(get_critical_attack() + 25);
  monster_level++;
}

void Aqua::reset() {
  set_strength(25 + ((monster_level - 1) * 25));
  set_health(160 + ((monster_level - 1) * 35));
  set_critical_attack(40 + ((monster_level - 1) * 25));
  ;
}

void Aqua::reset_for_load(int player_level) {
  set_strength(25 + ((player_level - 1) * 25));
  set_health(160 + ((player_level - 1) * 35));
  set_critical_attack(40 + ((player_level - 1) * 25));
}

int Aqua::attack(int attack_type, string opponent_type) {
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
    default:
      return strength;
  }
}

Aqua::~Aqua() {}