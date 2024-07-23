#include "Monster.h"

Monster::Monster(int health, int strength, int critical_attack)
    : health(health), strength(strength), critical_attack(critical_attack) {
  monster_level = 1;
}

Monster::Monster(int health, int strength)
    : health(health), strength(strength) {}

void Monster::set_strength(int new_strength) { strength = new_strength; }

void Monster::set_health(int new_health) { health = new_health; }

void Monster::set_critical_attack(int new_critical_attack) {
  critical_attack = new_critical_attack;
}

void Monster::set_monster_level(int new_level) { monster_level = new_level; }

int Monster::get_strength() { return strength; }

int Monster::get_health() { return health; }

int Monster::get_critical_attack() { return critical_attack; }

int Monster::get_monster_level() { return monster_level; }
string Monster::get_skill_name() { return skill_name; }
string Monster::get_monster_name() { return monster_name; }

void Monster::reset() { return; }

void Monster::reFill() { return; }

void Monster::reset_for_load(int player_level) { return; }

Monster::~Monster() {}
