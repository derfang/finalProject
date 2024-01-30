#include "PlayerAndList.h"

#include <bits/stdc++.h>

#include "ListOfWeapon.h"
#include "WeaponAndListOfWeapon.h"

using namespace std;

listOfPlayers::listOfPlayers() {}
void listOfPlayers::addPlayer(string playerName, string playerTeam,
                              string playerState, string time) {
  Player newPlayer(playerName, playerTeam, playerState, time);
  players.push_back(newPlayer);
}
void listOfPlayers::addWeapon(string playerName, string weaponName,
                              string team) {
  for (int i = 0; i < players.size(); i++) {
    if (players[i].name == playerName) {
      players[i].weapons.addWeapon(weaponName, team);
      break;
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
      break;
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

bool listOfPlayers::alreadyAdded(string playerName) {
  // Implement the logic to check if the player is already added
  // and return true or false accordingly
  for (int i = 0; i < players.size(); i++) {
    if (players[i].name == playerName) {
      return true;
    }
  }
  return false;
}

int listOfPlayers::howManyPlayers(string team) {
  // Implement the logic to count the number of players in the team
  // and return the count
  if (team == "all") {
    return players.size();
  }
  int counter = 0;
  for (int i = 0; i < players.size(); i++) {
    if (players[i].team == team) {
      counter++;
    }
  }
  return counter;
}

int listOfPlayers::findPlayer(string playerName) {
  for (int i = 0; i < players.size(); i++) {
    if (players[i].name == playerName) {
      return i;
    }
  }
  return -1;
}

void listOfPlayers::printScoreBoard() {  // we sort each team by fist kills than
                                         // deaths(the less the better) and
                                         // lastly by join time
  vector<Player> counterTerroristteam;
  vector<Player> terroristteam;
  for (int i = 0; i < players.size(); i++) {
    if (players[i].team == "Counter-Terrorist") {
      counterTerroristteam.push_back(players[i]);
    } else {
      terroristteam.push_back(players[i]);
    }
  }
  vector<Player> sortedCounterTerroristteam = counterTerroristteam;
  vector<Player> sortedTerroristteam = terroristteam;
  sort(sortedCounterTerroristteam.begin(), sortedCounterTerroristteam.end(),
       [](Player a, Player b) {
         if (a.kills == b.kills) {
           if (a.deaths == b.deaths) {
             return a.joinedTime < b.joinedTime;
           }
           return a.deaths < b.deaths;
         }
         return a.kills > b.kills;
       });
  sort(sortedTerroristteam.begin(), sortedTerroristteam.end(),
       [](Player a, Player b) {
         if (a.kills == b.kills) {
           if (a.deaths == b.deaths) {
             return a.joinedTime < b.joinedTime;
           }
           return a.deaths < b.deaths;
         }
         return a.kills > b.kills;
       });
  cout << "Counter-Terrorist-Players:" << endl;
  for (int i = 0; i < sortedCounterTerroristteam.size(); i++) { // <rank> <username> <kills> <death>
    cout << i + 1 << ' ' << sortedCounterTerroristteam[i].name << ' '
         << sortedCounterTerroristteam[i].kills << ' '
         << sortedCounterTerroristteam[i].deaths << endl;
  }
  cout << "Terrorist-Players:" << endl;
  for (int i = 0; i < sortedTerroristteam.size(); i++) { // <rank> <username> <kills> <death>
    cout << i + 1 << ' ' << sortedTerroristteam[i].name << ' '
         << sortedTerroristteam[i].kills << ' '
         << sortedTerroristteam[i].deaths << endl;
  }
}
