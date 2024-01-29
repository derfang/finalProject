#include "PlayerAndList.h"
#include "WeaponAndListOfWeapon.h"
#include <bits/stdc++.h>

using namespace std;

Player::Player() {}
Player::Player(string playerName, string playerTeam, string playerState) {
  name = playerName;
  team = playerTeam;
  health = 100;
  money = 1000;
  kills = 0;
  deaths = 0;
  state = playerState;
}

listOfPlayers::listOfPlayers() {}
void listOfPlayers::addPlayer(string playerName, string playerTeam,
                              string playerState) {
  Player newPlayer(playerName, playerTeam, playerState);
  players.push_back(newPlayer);
}
void listOfPlayers::addWeapon(string playerName, string weaponName,
                              string team) {
  for (int i = 0; i < players.size(); i++) {
    if (players[i].name == playerName) {
      players[i].weapons.addWeapon(weaponName, team);
    }
  }
}
void listOfPlayers::printPlayerInfo(string playerName) {
  for (int i = 0; i < players.size(); i++) {
    if (players[i].name == playerName) {
      cout << "name: " << players[i].name << endl;
      cout << "health: " << players[i].health << endl;
      cout << "money: " << players[i].money << endl;
      cout << "kills: " << players[i].kills << endl;
      cout << "deaths: " << players[i].deaths << endl;
      cout << "state: " << players[i].state << endl;
      cout << "team: " << players[i].team << endl;
      cout << "heavy weapon: " << players[i].weapons.heavy.name << endl;
      cout << "pistol: " << players[i].weapons.pistol.name << endl;
      cout << "knife: " << players[i].weapons.knife.name << endl;
    }
  }
}
void listOfPlayers::printAllPlayersInfo() {
  for (int i = 0; i < players.size(); i++) {
    cout << "name: " << players[i].name << endl;
    cout << "health: " << players[i].health << endl;
    cout << "money: " << players[i].money << endl;
    cout << "kills: " << players[i].kills << endl;
    cout << "deaths: " << players[i].deaths << endl;
    cout << "state: " << players[i].state << endl;
    cout << "team: " << players[i].team << endl;
    cout << "heavy weapon: " << players[i].weapons.heavy.name << endl;
    cout << "pistol: " << players[i].weapons.pistol.name << endl;
    cout << "knife: " << players[i].weapons.knife.name << endl;
  }
}
