// Creator: Erfan Ghasry q: why dont u answer my question at the main function? a: because i dont want to
// Brief:
//? this is a simple simulator for counter-strike if it was a console game
//? we get every game event from a single user input and then react to it immediately
//? we get the number of rounds in every game then we get the number of events in every round
//? then we get the events and react to them
//? at the end of every round we print out the winner of the round

#include <bits/stdc++.h>
#include "src/additional_functions.h"
#include "src/WeaponAndListOfWeapon.h"
#include "src/PlayerAndList.h"

using namespace std;



int main(int argc, char const *argv[]){
    command_line_arguments(argc, argv);
    //----------------------------------------
    // int roundNum = 0;
    // listOfPlayers players;
    // string currentTime = "0:00:000";
    // string line;
    // getline(cin, line);
    // roundNum = stoi(line);
    // for(int i = 0; i < roundNum; i++){
    //     int eventNum = 0;
    //     getline(cin, line);
    //     vector<string> vectorOfInstructions = split(line);
    //     while (vectorOfInstructions[0] != "ROUND"){
    //         getline(cin, line);
    //         vectorOfInstructions = split(line);
    //     }
    //     eventNum = stoi(vectorOfInstructions[1]);

    //     for(int j = 0; j < eventNum; j++){
    //         while(true){ // make sure the time is always increasing
    //         getline(cin, line);
    //         vectorOfInstructions = split(line);
    //         if (vectorOfInstructions.back() > currentTime){
    //             currentTime = vectorOfInstructions.back();
    //             break;
    //         }
    //         else {
    //             cout << "invalid time" << endl;
    //         }
    //         }
    //         if (vectorOfInstructions[0] == "ADD-USER"){
                





                
                

                
        




    

    return 0;
}



// void help() {
//     cout << "this is a simple simulator for counter-strike if it was a console game\n";
//     cout << "we get every game event from a single user input and then react to it immediately\n";
//     cout << "we get the number of rounds in every game then we get the number of events in every round\n";
//     cout << "then we get the events and react to them\n";
//     cout << "at the end of every round we print out the winner of the round\n";
//     cout << endl;
//     cout << "to seek additional help, please contact the developer at: \n";
//     cout << "   " << "https://github.com/derfang/finalProject" << endl;
// }

// //? This function will print the version of the program
// void version() { cout << "console Counter-Strike version 0.1.0" << endl; }

// //? This function will handle the command line arguments
// void command_line_arguments(int argc, char const *argv[]) {
//     help();
//   if (argc >= 2) {
//     string user_input = argv[1];
//     if (user_input == "-h" || user_input == "--help") {
//       help();
//       exit(0);
//     } else if (user_input == "-v" || user_input == "--version") {
//       version();
//       exit(0);
//     } else {
//       cout << "Invalid input, please enter -h or --help for help" << endl;
//       exit(0);
//     }
//   }
// }

// //? This function will split a string into a vector of strings
// vector<string> split (const string &s, char delim = ' ') {
//     vector<string> result;
//     stringstream ss (s);
//     string item;
//     while (std::getline (ss, item, delim)) {
//         result.push_back (item);
//     }
//     return result;
// }

// class Weapon { //todo using enum
//     public:
//         string name;
//         string type;
//         string userType;
//         int damage;
//         int price;
//         int killAward;
//         Weapon(){}
//         Weapon(string weaponName){// knife, AK, AWP, Revolver, Glock-18, M4A1, Desert-Eagle, UPS-S
//             if (weaponName == "knife"){
//                 name = "knife";
//                 type = "knife";
//                 userType = "both";
//                 damage = 43;
//                 price = 0;
//                 killAward = 500;
//             }
//             else if (weaponName == "AK"){
//                 name = "AK";
//                 type = "heavy";
//                 userType = "Terrorist";
//                 damage = 31;
//                 price = 2700;
//                 killAward = 100;
//             }
//             else if (weaponName == "AWP"){
//                 name = "AWP";
//                 type = "heavy";
//                 userType = "Terrorist";
//                 damage = 110;
//                 price = 4300;
//                 killAward = 50;
//             }
//             else if (weaponName == "Revolver"){
//                 name = "Revolver";
//                 type = "pistol";
//                 userType = "Terrorist";
//                 damage = 51;
//                 price = 600;
//                 killAward = 150;
//             }
//             else if (weaponName == "Glock-18"){
//                 name = "Glock-18";
//                 type = "pistol";
//                 userType = "Terrorist";
//                 damage = 11;
//                 price = 300;
//                 killAward = 200;
//             }
//             else if (weaponName == "M4A1"){
//                 name = "M4A1";
//                 type = "heavy";
//                 userType = "both";
//                 damage = 29;
//                 price = 2700;
//                 killAward = 100;
//             }
//             else if (weaponName == "Desert-Eagle"){
//                 name = "Desert-Eagle";
//                 type = "pistol";
//                 userType = "Counter-Terrorist";
//                 damage = 53;
//                 price = 600;
//                 killAward = 175;
//             }
//             else if (weaponName == "UPS-S"){
//                 name = "UPS-S";
//                 type = "pistol";
//                 userType = "Counter-Terrorist";
//                 damage = 13;
//                 price = 300;
//                 killAward = 225;
//             }
//             else {
//                 throw runtime_error("invalid input");
//             }
//         }
// };

// class ListOfWeapons { //todo turn "cout"s to exptation massages then print them in catch block
//     public:
//         Weapon heavy;
//         Weapon pistol;
//         Weapon knife;
//         ListOfWeapons(){
//             knife = Weapon("knife");
//         }
//         void addWeapon(string weaponName, string team){
//             try{
//                 Weapon newWeapon(weaponName);
//                 if (newWeapon.type == "heavy"){
//                     if (heavy.name == ""){
//                         if (newWeapon.userType == team || newWeapon.userType == "both"){
//                             heavy = newWeapon;
//                         }
//                         else {
//                             cout << "invalid category gun" << endl;
//                             throw runtime_error("you can't use this weapon");
//                         }
//                     }
//                     else {
//                         cout << "you have a " << heavy.name << endl; 
//                         throw runtime_error("heavy weapon already exists");
//                     }
//                 }
//                 else if (newWeapon.type == "pistol"){
//                     if (pistol.name == ""){
//                         if (newWeapon.userType == team || newWeapon.userType == "both"){
//                             pistol = newWeapon;
//                         }
//                         else {
//                             cout << "invalid category gun" << endl;
//                             throw runtime_error("you can't use this weapon");
//                         }
//                     }
//                     else {
//                         cout << "you have a " << pistol.name << endl; 
//                         throw runtime_error("pistol already exists");
//                     }
//                 }
//                 else {
//                     throw runtime_error("invalid input");
//                 }
//             }
//             catch (runtime_error &e){
//                 cout << e.what() << endl;
//                 throw runtime_error("somthing went wrong");
//             }
//         }
// };

// class Player {
//     public:
//         string name;
//         int health;
//         int money;
//         int kills;
//         int deaths;
//         ListOfWeapons weapons;
//         string team;
//         string state;
//         Player(){}
//         Player(string playerName, string playerTeam, string playerState){
//             name = playerName;
//             team = playerTeam;
//             health = 100;
//             money = 1000;
//             kills = 0;
//             deaths = 0;
//             state = playerState;
//         }
// };

// class listOfPlayers{
//     public:
//         vector<Player> players;
//         listOfPlayers(){}
//         void addPlayer(string playerName, string playerTeam, string playerState){
//             Player newPlayer(playerName, playerTeam, playerState);
//             players.push_back(newPlayer);
//         }
//         void addWeapon(string playerName, string weaponName, string team){
//             for (int i = 0; i < players.size(); i++){
//                 if (players[i].name == playerName){
//                     players[i].weapons.addWeapon(weaponName, team);
//                 }
//             }
//         }
//         void printPlayerInfo(string playerName){
//             for (int i = 0; i < players.size(); i++){
//                 if (players[i].name == playerName){
//                     cout << "name: " << players[i].name << endl;
//                     cout << "health: " << players[i].health << endl;
//                     cout << "money: " << players[i].money << endl;
//                     cout << "kills: " << players[i].kills << endl;
//                     cout << "deaths: " << players[i].deaths << endl;
//                     cout << "state: " << players[i].state << endl;
//                     cout << "team: " << players[i].team << endl;
//                     cout << "heavy weapon: " << players[i].weapons.heavy.name << endl;
//                     cout << "pistol: " << players[i].weapons.pistol.name << endl;
//                     cout << "knife: " << players[i].weapons.knife.name << endl;
//                 }
//             }
//         }
//         void printAllPlayersInfo(){
//             for (int i = 0; i < players.size(); i++){
//                 cout << "name: " << players[i].name << endl;
//                 cout << "health: " << players[i].health << endl;
//                 cout << "money: " << players[i].money << endl;
//                 cout << "kills: " << players[i].kills << endl;
//                 cout << "deaths: " << players[i].deaths << endl;
//                 cout << "state: " << players[i].state << endl;
//                 cout << "team: " << players[i].team << endl;
//                 cout << "heavy weapon: " << players[i].weapons.heavy.name << endl;
//                 cout << "pistol: " << players[i].weapons.pistol.name << endl;
//                 cout << "knife: " << players[i].weapons.knife.name << endl;
//             }
//         }
// };

  
