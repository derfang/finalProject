#pragma once
#include <bits/stdc++.h>

#include "WeaponAndListOfWeapon.h"
using namespace std;

class ListOfWeapons {  // todo turn "cout"s to exptation massages then print
                       // them in catch block
 public:
  Weapon heavy;
  Weapon pistol;
  Weapon knife;
  ListOfWeapons();
  void addWeapon(string weaponName, string team);
  bool weaponExists(string weaponType);
  Weapon getWeapon(string weaponType);
  void clear();
};

class Player {
 public:
  string name;
  int health;
  int money;
  int kills;
  int deaths;
  ListOfWeapons weapons;
  string team;
  string state;
  string joinedTime;
  Player();
  Player(string playerName, string playerTeam, string playerState, string time);
  bool operator>(const Player &other);
};