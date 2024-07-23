#ifndef ABYSSGAME_H
#define ABYSSGAME_H

#include <time.h>
#include <unistd.h>

#include <iostream>
#include <string>

#include "Machine.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

class abyssGame {
 private:
  Player* game_player;
  Machine* game_machine;

 public:
  // Detail explaination of each function is in cpp file
  abyssGame();
  int game_menu();
  void new_game();
  void go_battle();
  abyssGame load_game();
  void level_up();
  void save_game();
};
#endif