#include "Machine.h"

Machine::Machine() {
  game_level = 1;
  machine_monster = nullptr;
}

// int Machine::get_level() { return game_level; }

// string Machine::get_monster_type() { return monster_type; }

Monster* Machine::get_monster() { return *machine_monster; }

void Machine::level_up() { game_level++; }

int Machine::get_strength() { return (*machine_monster)->get_strength(); }

void Machine::set_monster(int index) {
  // we already delete this with deconstructor -> avoid double-deletetion -> no
  // segfault if (game_level != 1) {
  //   delete *machine_monster;
  // }
  machine_monster = new Monster*;
  switch (index) {
    case 0:
      *machine_monster = new Dragon(game_level);
      monster_type = "Dragon";
      break;
    case 1:
      *machine_monster = new Serbine(game_level);
      monster_type = "Serbine";
      break;
    case 2:
      *machine_monster = new Titan(game_level);
      monster_type = "Titan";
      break;
    case 3:
      *machine_monster = new Aqua(game_level);
      monster_type = "Aqua";
      break;
    default:
      machine_monster = nullptr;
  }
}

void Machine::take_attack(int strength) {
  int new_health = (**machine_monster).get_health() - strength;
  (**machine_monster).set_health(new_health);
}

void Machine::set_game_level(int _game_level) { game_level = _game_level; }

void Machine::display_attack() {
  cout << "You take " << get_strength() << " damage." << endl;
  // object machine display the state of object monster
}

Machine::~Machine() { delete *machine_monster; }
