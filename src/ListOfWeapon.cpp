#include "ListOfWeapon.h"

#include <bits/stdc++.h>

#include "WeaponAndListOfWeapon.h"

using namespace std;

ListOfWeapons::ListOfWeapons() { knife = Weapon("knife"); }

void ListOfWeapons::addWeapon(string weaponName, string team) {
  try {
    Weapon newWeapon(weaponName);
    if (newWeapon.type == "heavy") {
      if (heavy.name == "") {
        if (newWeapon.userType == team || newWeapon.userType == "both") {
          heavy = newWeapon;
        } else {
          cout << "invalid category gun" << endl;
          throw runtime_error("you can't use this weapon");
        }
      } else {
        cout << "you have a " << heavy.name << endl;
        throw runtime_error("heavy weapon already exists");
      }
    } else if (newWeapon.type == "pistol") {
      if (pistol.name == "") {
        if (newWeapon.userType == team || newWeapon.userType == "both") {
          pistol = newWeapon;
        } else {
          cout << "invalid category gun" << endl;
          throw runtime_error("you can't use this weapon");
        }
      } else {
        cout << "you have a " << pistol.name << endl;
        throw runtime_error("pistol already exists");
      }
    } else {
      throw runtime_error("invalid input");
    }
  } catch (runtime_error &e) {
    //? next line is for debugging
    // cout << "here is lsit::addweapon : " << e.what() << endl;
    throw runtime_error("somthing went wrong");
  }
}

bool ListOfWeapons::weaponExists(string weaponType) {
  if (weaponType == "heavy") {
    if (heavy.name == "") {
      return false;
    } else {
      return true;
    }
  } else if (weaponType == "pistol") {
    if (pistol.name == "") {
      return false;
    } else {
      return true;
    }
  } else if (weaponType == "knife") {
    if (knife.name == "") {
      return false;
    } else {
      return true;
    }
  } else {
    cout << "im here : weaponExists" << endl;
    throw runtime_error("invalid input");
  }
}

Weapon ListOfWeapons::getWeapon(string weaponType) {
  if (weaponType == "heavy") {
    return heavy;
  } else if (weaponType == "pistol") {
    return pistol;
  } else if (weaponType == "knife") {
    return knife;
  } else {
    cout << "im here : get weapon" << endl;
    throw runtime_error("invalid input weapon type");
  }
}

void ListOfWeapons::clear() {
  heavy = Weapon();
  pistol = Weapon();
}

Player::Player() {}
Player::Player(string playerName, string playerTeam, string playerState, string time) {
  name = playerName;
  team = playerTeam;
  if (playerState == "DEAD") {
    health = 0;
  } else if (playerState == "ALIVE") {
    health = 100;
  } else {
    cout << "im here : Player" << endl;
    throw runtime_error("invalid input of playes state");
  }
  money = 1000;
  kills = 0;
  deaths = 0;
  state = playerState;
  joinedTime = time;
}
