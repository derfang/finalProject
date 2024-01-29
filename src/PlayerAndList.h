#pragma once
#include <bits/stdc++.h>
#include "WeaponAndListOfWeapon.h"
using namespace std;

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
  Player();
  Player(string playerName, string playerTeam, string playerState);
};

class listOfPlayers {
 public:
  vector<Player> players;
  listOfPlayers();
  void addPlayer(string playerName, string playerTeam, string playerState);
  void addWeapon(string playerName, string weaponName, string team);
  void printPlayerInfo(string playerName);
  void printAllPlayersInfo();
};
