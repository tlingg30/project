#ifndef MONSTER_H
#define MONSTER_H
#include <cmath>
#include <string>
using namespace std;
class Monster {
 protected:
  int health;
  int strength;
  int monster_level;
  int critical_attack;
  string skill_name;
  string monster_name;

 public:
  // constructor for player monster
  Monster(int health, int strength, int critical_attack);
  // constructor for machine monster
  Monster(int health, int strength);

  void set_strength(int new_strength);
  void set_health(int new_health);
  void set_critical_attack(int new_critical_attack);
  void set_monster_level(int new_level);

  int get_strength();
  int get_health();
  int get_critical_attack();
  int get_monster_level();
  string get_skill_name();
  string get_monster_name();

  virtual void reset();
  virtual void reFill();
  virtual void reset_for_load(int player_level);
  virtual int attack(int attack_type, string opponent_type) = 0;
  virtual ~Monster();
};

#endif