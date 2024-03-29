#include <bits/stdc++.h>
using namespace std;
#include "WeaponAndListOfWeapon.h"

Weapon::Weapon() {}

Weapon::Weapon(string weaponName) {  // knife, AK, AWP, Revolver, Glock-18,
                                     // M4A1, Desert-Eagle, UPS-S
  if (weaponName == "knife") {
    name = "knife";
    type = "knife";
    userType = "both";
    damage = 43;
    price = 0;
    killAward = 500;
  } else if (weaponName == "AK") {
    name = "AK";
    type = "heavy";
    userType = "Terrorist";
    damage = 31;
    price = 2700;
    killAward = 100;
  } else if (weaponName == "AWP") {
    name = "AWP";
    type = "heavy";
    userType = "Terrorist";
    damage = 110;
    price = 4300;
    killAward = 50;
  } else if (weaponName == "Revolver") {
    name = "Revolver";
    type = "pistol";
    userType = "Terrorist";
    damage = 51;
    price = 600;
    killAward = 150;
  } else if (weaponName == "Glock-18") {
    name = "Glock-18";
    type = "pistol";
    userType = "Terrorist";
    damage = 11;
    price = 300;
    killAward = 200;
  } else if (weaponName == "M4A1") {
    name = "M4A1";
    type = "heavy";
    userType = "both";
    damage = 29;
    price = 2700;
    killAward = 100;
  } else if (weaponName == "Desert-Eagle") {
    name = "Desert-Eagle";
    type = "pistol";
    userType = "Counter-Terrorist";
    damage = 53;
    price = 600;
    killAward = 175;
  } else if (weaponName == "UPS-S") {
    name = "UPS-S";
    type = "pistol";
    userType = "Counter-Terrorist";
    damage = 13;
    price = 300;
    killAward = 225;
  } else {
    throw runtime_error("invalid input");
  }
}




