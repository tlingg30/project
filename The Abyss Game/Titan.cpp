#include "Titan.h"

#include <iostream>
Titan::Titan() : Monster(250, 10, 25) { monster_name = "Titan"; }

Titan::Titan(int game_level)
    : Monster(400 + ((game_level - 1) * 200), 10 + ((game_level - 1) * 10)) {}

int Titan::attack(int attack_type, string opponent_type) {
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
        // std::cout<<"Remained health is: "<<health<<std::endl;
        return (strength * 3);
      } else {
        health = health - ((0.015 * monster_level) * health);
        // std::cout<<"Remained health is: "<<health<<std::endl;
        return (strength * 2);
      }
      break;
    default:
      return strength;
  }
}

void Titan::reFill() {
  set_strength(get_strength() + 10);
  set_health(get_health() + 60);
  set_critical_attack(get_critical_attack() + 10);
  monster_level++;
}

void Titan::reset() {
  set_strength(15 + ((monster_level - 1) * 10));
  set_health(250 + ((monster_level - 1) * 60));
  set_critical_attack(25 + ((monster_level - 1) * 10));
}

void Titan::reset_for_load(int player_level) {
  set_strength(15 + ((player_level - 1) * 10));
  set_health(250 + ((player_level - 1) * 60));
  set_critical_attack(25 + ((player_level - 1) * 10));
}

Titan::~Titan() {}
