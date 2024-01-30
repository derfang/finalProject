#pragma once
#include <bits/stdc++.h>
#include "WeaponAndListOfWeapon.h"
#include "ListOfWeapon.h"
using namespace std;

class listOfPlayers{
    public:
        vector<Player> players;
        listOfPlayers();
        void addPlayer(string playerName, string playerTeam, string playerState, string time);
        void addWeapon(string playerName, string weaponName, string team);
        void printPlayerInfo(string playerName);
        void printAllPlayersInfo();
        bool alreadyAdded(string playerName);
        int howManyPlayers(string team = "all");
        int findPlayer(string playerName);
        void printScoreBoard();
};



