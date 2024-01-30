// Creator: Erfan Ghasry q: why dont u answer my question at the main function? a: because i dont want to
// Brief:
//? this is a simple simulator for counter-strike if it was a console game
//? we get every game event from a single user input and then react to it immediately
//? we get the number of rounds in every game then we get the number of events in every round
//? then we get the events and react to them
//? at the end of every round we print out the winner of the round

#include <bits/stdc++.h>
#include "src/additional_functions.h"
#include "src/ListOfWeapon.h"
#include "src/ListofWeapon.cpp"
#include "src/PlayerAndList.h"

using namespace std;

int main(int argc, char const *argv[]){
    command_line_arguments(argc, argv);
    //-------------------------------now we implement the game----------------------------------------
    int roundNum = 0;
    listOfPlayers players;
    string currentTime = "00:00:000";
    string line;
    getline(cin, line);
    roundNum = stoi(line);
    for(int i = 0; i < roundNum; i++){ // a game consists of a given number of rounds
        int eventNum = 0;
        getline(cin, line);
        vector<string> vectorOfInstructions = split(line);
        while (vectorOfInstructions[0] != "ROUND"){// ensure that the first instruction is "ROUND" as it should be
            cout << "you must start with a \"ROUND\" instruction" << endl;
            getline(cin, line);
            vectorOfInstructions = split(line);
        }
        eventNum = stoi(vectorOfInstructions[1]);

        for(int j = 0; j < eventNum; j++){// iterate through the events of the round
            while(true){ // make sure the time is always increasing and in the valid time span
                getline(cin, line);
                vectorOfInstructions = split(line);
                if (vectorOfInstructions.back() > currentTime && vectorOfInstructions.back() < "02:15:000"){
                    currentTime = vectorOfInstructions.back();
                    break;
                }
                else {
                    cout << "invalid time" << endl;
                }
            }
            //------------------now the look-up-table for the events------------------
            if (vectorOfInstructions[0] == "ADD-USER"){
                if (players.alreadyAdded(vectorOfInstructions[1]) == true){
                    cout << "you are already in this game" << endl;
                }
                else if (players.howManyPlayers(vectorOfInstructions[2]) == 10){
                    cout << "this team is full" << endl;
                }
                else if (vectorOfInstructions.back() > "00:02:999"){
                    players.addPlayer(vectorOfInstructions[1], // playerName
                                      vectorOfInstructions[2], // playerTeam
                                      "DEAD", // playerState
                                      vectorOfInstructions.back()); // joinedTime
                    cout << "this user added to " << vectorOfInstructions[2] << endl;
                }
                else {
                    players.addPlayer(vectorOfInstructions[1], // playerName
                                      vectorOfInstructions[2], // playerTeam
                                      "ALIVE", // playerState
                                      vectorOfInstructions.back()); // joinedTime
                    cout << "this user added to " << vectorOfInstructions[2] << endl;
                }
            }
            else if (vectorOfInstructions[0] == "GET-MONEY"){
                int index = players.findPlayer(vectorOfInstructions[1]); // index of the player in the vector
                if (index == -1){
                    cout << "invalid username" << endl;
                }
                else {
                    cout << players.players[index].money << endl;
                }
            }
            else if (vectorOfInstructions[0] == "GET-HEALTH"){
                int index = players.findPlayer(vectorOfInstructions[1]); // index of the player in the vector
                if (index == -1){
                    cout << "invalid username" << endl;
                }
                else {
                    cout << players.players[index].health << endl;
                }
            }
            else if (vectorOfInstructions[0] == "TAP"){  // TAP <attacker> <attacked> [heavy/pistol/knife] <time>
                int attakerIndex = players.findPlayer(vectorOfInstructions[1]);
                int attackedIndex = players.findPlayer(vectorOfInstructions[2]);
                if (attackedIndex == -1 || attakerIndex == -1){
                    cout << "invalid username" << endl;
                }
                else if (players.players[attakerIndex].state == "DEAD"){
                    cout << "attacker is dead" << endl;
                }
                else if (players.players[attackedIndex].state == "DEAD"){
                    cout << "attacked is dead" << endl;
                }
                else if (players.players[attakerIndex].weapons.weaponExists(vectorOfInstructions[3]) == false){
                    cout << "no such gun" << endl;
                }
                else if (players.players[attakerIndex].team == players.players[attackedIndex].team){
                    cout << "friendly fire" << endl;
                }
                else {
                    players.players[attackedIndex].health -= players.players[attakerIndex].weapons.getWeapon(vectorOfInstructions[3]).damage;
                    if (players.players[attackedIndex].health <= 0){
                        players.players[attackedIndex].state = "DEAD";
                        players.players[attackedIndex].health = 0;
                        players.players[attakerIndex].kills++;
                        players.players[attackedIndex].deaths++;
                        players.players[attakerIndex].money += players.players[attakerIndex].weapons.getWeapon(vectorOfInstructions[3]).killAward;
                        if (players.players[attakerIndex].money > 10000){
                            players.players[attakerIndex].money = 10000;
                        }
                    }
                    cout << "nice shot" << endl;
                }
            }
            else if (vectorOfInstructions[0] == "BUY"){//BUY <username> <gun_name> <time>
                int index = players.findPlayer(vectorOfInstructions[1]); // index of the player in the vector
                Weapon desierdWeapon(vectorOfInstructions[2]);
                if (index == -1){
                    cout << "invalid username" << endl;
                }
                else if (players.players[index].state == "DEAD"){
                    cout << "deads can not buy" << endl;
                }
                else if (vectorOfInstructions.back() > "00:44:999"){
                    cout << "you are out of time" << endl;
                }
                else if (players.players[index].money < desierdWeapon.price){
                    cout << "no enough money" << endl; //todo its a bit fishy
                }
                else{
                    try{
                        string team = players.players[index].team;
                        players.players[index].weapons.addWeapon(vectorOfInstructions[2], team);
                        players.players[index].money -= desierdWeapon.price;
                        cout << "I hope you can use it" << endl;
                    }
                    catch (runtime_error& e){
                        // ?next line is for debugging
                        // cout << "here is main : " << e.what() << endl;
                    }
                }
            }
            else if (vectorOfInstructions[0] == "SCORE-BOARD"){
                players.printScoreBoard();
            }
        }
        //------------------now we print the winner of the round------------------
        bool isThereAnyCounterTerroristsAlive = false;
        bool isThereAnyTerroristsAlive = false;
        string winner = "";

        for(int i = 0; i < players.players.size(); i++){
            if (players.players[i].team == "Counter-Terrorist" && players.players[i].state == "ALIVE"){
                isThereAnyCounterTerroristsAlive = true;
            }
            else if (players.players[i].team == "Terrorist" && players.players[i].state == "ALIVE"){
                isThereAnyTerroristsAlive = true;
            }
        }
        if (isThereAnyTerroristsAlive == true && isThereAnyCounterTerroristsAlive == false){
            cout << "Terrorist won" << endl;
            winner = "Terrorist won";
        }
        else {
            cout << "Counter-Terrorist won" << endl;
            winner = "Counter-Terrorist";
        }
        //-----------now we reset--------------------
        for(int i = 0; i < players.players.size(); i++){
            players.players[i].health = 100;
            players.players[i].state = "ALIVE";
            if (players.players[i].state == "DEAD"){
                players.players[i].weapons.clear();
            }
            players.players[i].money += (players.players[i].team == winner) ? 2700 : 2400;
            //todo: use a setter for money to insure it wont excess 10000
            if (players.players[i].money > 10000){
                players.players[i].money = 10000;
            }
        }
        currentTime = "00:00:000";
    }

    return 0;
}



