#include "Serbine.h"

Serbine::Serbine() : Monster(180, 20, 35) { monster_name = "Serbine"; }

Serbine::Serbine(int game_level)
    : Monster(400 + ((game_level - 1) * 200), 10 + ((game_level - 1) * 10)) {}

void Serbine::reFill() {
  set_strength(get_strength() + 20);
  set_health(get_health() + 55);
  set_critical_attack(get_critical_attack() + 20);
  monster_level++;
}

void Serbine::reset() {
  set_strength(20 + ((monster_level - 1) * 20));
  set_health(180 + ((monster_level - 1) * 55));
  set_critical_attack(35 + ((monster_level - 1) * 20));
}

void Serbine::reset_for_load(int player_level) {
  set_strength(20 + ((player_level - 1) * 20));
  set_health(180 + ((player_level - 1) * 55));
  set_critical_attack(35 + ((player_level - 1) * 20));
}

int Serbine::attack(int attack_type, string opponent_type) {
  switch (attack_type) {
    case 1:
      if (opponent_type == "Titan") {
        return strength * 1.5;
      } else {
        return strength;
      }
      break;
    case 2:
      if (opponent_type == "Titan") {
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

Serbine::~Serbine() {}