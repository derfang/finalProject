#pragma once
#include <bits/stdc++.h>
using namespace std;


class Weapon { //todo using enum
    public:
        string name;
        string type;
        string userType;
        int damage;
        int price;
        int killAward;
        Weapon();
        Weapon(string weaponName);
};


class ListOfWeapons { //todo turn "cout"s to exptation massages then print them in catch block
    public:
        Weapon heavy;
        Weapon pistol;
        Weapon knife;
        ListOfWeapons();
        void addWeapon(string weaponName, string team);
};
