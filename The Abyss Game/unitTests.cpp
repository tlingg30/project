#include <iostream>

#include "Monster.h"
#include "Player.h"
#include "SuperAqua.h"
string Machine::monster_type;
int Machine::game_level;
class UnitTest {
 private:
  void test_attack_setter_getter() {
    Player player("Linh");  // level 1
    if (player.get_coins() == 0 && player.get_player_level() == 1) {
      cout << "Test 1 (passed) - Get player coins  / Get player level" << endl;
    } else {
      cout << "Test 1 (failed) - Get player coins / Get player level" << endl;
    }
    Machine machine;  // level 1
    player.set_monster("Aqua");
    int strength_player =
        player.get_monster_list()[player.get_current_monster()]->get_strength();
    if (strength_player == 25) {
      cout << "Test 2 (passed) - Get player strength  / Get current monster / "
              "get monster list"
           << endl;
    } else {
      cout << "Test 2 (failed) - Get player strength / Get current monster / "
              "get monster list "
           << endl;
    }
    machine.set_monster(2);
    if (machine.monster_type == "Titan") {
      cout << "Test 3 (passed) - Get machine monster type" << endl;
    } else {
      cout << "Test 3 (failed) - Get machine monster type " << endl;
    }
    machine.take_attack(strength_player);
    if (machine.get_monster()->get_health() == (400 - 25)) {
      cout << "Test 4 (passed) - Player attack and Machine take attack" << endl;
    } else {
      cout << "Test 4 (failed) - Player attack and Machine take attack "
           << endl;
      // if passed meaning get_monster_list(), get_current_monster() and
      // get_strength() also passed.
    }
    int strength_machine = machine.get_strength();
    player.take_attack(strength_machine);
    if (player.get_monster_list()[player.get_current_monster()]->get_health() ==
        (160 - 10)) {
      cout << "Test 5 (passed) - Machine attack and Player take attack "
           << endl;
    } else {
      cout << "Test 5 (failed) - Machine attack and Player take attack" << endl;
    }
    player.reset();
    if (player.get_monster_list()[player.get_current_monster()]->get_health() ==
        160) {
      cout << "Test 6 (passed) - Reset to pre-battle stats" << endl;
    } else {
      cout << "Test 6 (failed) - Reset to pre-battle stats" << endl;
    }
  }

  void test_level_up() {
    Player player("Bao");
    player.set_coins(1000);
    player.level_up();  // refill() would also pass
    if (player.get_player_level() != 2) {
      cout << "Test 7 (failed)) - player level update" << endl;
    } else {
      cout << "Test 7 (passed) - player level update " << endl;
    }
    if (player.get_coins() != (1000 - 150)) {
      cout << "Test 8 (failed) - player coin update " << endl;
    } else {
      cout << "Test 8 (passed) - player coin update " << endl;
    }
    if (player.get_monster_list()[player.get_current_monster()]
            ->get_monster_level() != 2) {
      cout << "Test 9 (failed) - player monster level update " << endl;
    } else {
      cout << "Test 9 (passed) - player monster level update " << endl;
    }
  }
  void test_reward() {
    Player player("Bao");
    player.reward(true);
    if (player.get_coins() != 160) {
      cout << "Test 10 (failed) - player coin win battle update " << endl;
    } else {
      cout << "Test 10 (passed) - player coin win battle update " << endl;
    }
    player.reward(false);
    if (player.get_coins() != 220) {
      cout << "Test 11 (failed) - player coin lose battle update " << endl;
    } else {
      cout << "Test 11 (passed) - player coin lose battle update " << endl;
    }
  }

 public:
  void runTests() {
    test_attack_setter_getter();
    test_level_up();
    test_reward();
  }
};

int main() {
  UnitTest test1;
  test1.runTests();
  return 0;
}