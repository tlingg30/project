#include "Player.h"

Player::Player() {
  player_level = 1;
  coins = 0;
}

Player::Player(string user_name) {
  player_level = 1;
  coins = 0;
  this->user_name = user_name;
  monster_list = new Monster*[4];
  monster_list[0] = new Dragon();
  monster_list[1] = new Titan();
  monster_list[2] = new Aqua();
  monster_list[3] = new Serbine();
}

bool Player::set_monster(string monster_name) {
  if (monster_name == "Dragon" || monster_name == "dragon") {
    this->current_monster = 0;
    return 1;
  } else if (monster_name == "Titan" || monster_name == "titan") {
    this->current_monster = 1;
    return 1;
  } else if (monster_name == "Aqua" || monster_name == "aqua") {
    this->current_monster = 2;
    return 1;
  } else if (monster_name == "Serbine" || monster_name == "serbine") {
    this->current_monster = 3;
    return 1;
  } else {
    cout << "Please check your spelling" << endl;
    return 0;
  }
}

int Player::get_current_monster() { return current_monster; }

int Player::get_player_level() { return player_level; }

int Player::get_coins() { return coins; }

string Player::get_player_name() { return user_name; }

void Player::set_coins(int new_coins) { coins = new_coins; }

void Player::set_player_name(string player_name) {
  this->user_name = player_level;
}

void Player::set_player_level(int player_level) {
  this->player_level = player_level;
}

Monster** Player::get_monster_list() { return monster_list; }

int Player::attack(Machine* opponent, int attack_type) {
  int strength =
      monster_list[current_monster]->attack(attack_type, Machine::monster_type);
  opponent->take_attack(strength);
  return strength;
}

void Player::take_attack(int strength) {
  int new_health = monster_list[current_monster]->get_health() - strength;
  monster_list[current_monster]->set_health(new_health);
}

void Player::level_up() {
  // if (coins >= (player_level + 1) * 100 - 50) {
  coins -= (player_level + 1) * 100 - 50;
  player_level++;
  for (int i = 0; i < 4; i++) {
    monster_list[i]->reFill();
  }
}

void Player::reset() { monster_list[get_current_monster()]->reset(); }

int Player::reward(bool win) {
  if (win) {
    int new_coins = get_coins() + (Machine::game_level * 60 + 100);
    set_coins(new_coins);
    return Machine::game_level * 60 + 100;
  } else {
    int new_coins = get_coins() + (Machine::game_level * 30 + 30);
    set_coins(new_coins);
    return Machine::game_level * 30 + 3;
  }
}

void Player::display_attack(int strength) {
  cout << "Machine takes " << strength << " damage" << endl;
}

Player::~Player() {}
