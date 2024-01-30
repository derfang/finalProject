// Creator: Erfan Ghasry q: why dont u answer my question at the main function? a: because i dont want to
// Brief:
//? this is a simple simulator for counter-strike if it was a console game
//? we get every game event from a single user input and then react to it immediately
//? we get the number of rounds in every game then we get the number of events in every round
//? then we get the events and react to them
//? at the end of every round we print out the winner of the round

#include <bits/stdc++.h>

using namespace std;

void help();
void version();
void command_line_arguments(int argc, char const *argv[]);
vector<string> split(const string &s, char delim = ' ');

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



void help() {
  cout << "this is a simple simulator for counter-strike if it was a console "
          "game\n";
  cout << "we get every game event from a single user input and then react to "
          "it immediately\n";
  cout << "we get the number of rounds in every game then we get the number of "
          "events in every round\n";
  cout << "then we get the events and react to them\n";
  cout << "at the end of every round we print out the winner of the round\n";
  cout << endl;
  cout << "to seek additional help, please contact the developer at: \n";
  cout << "   "
       << "https://github.com/derfang/finalProject" << endl;
}

//? This function will print the version of the program
void version() { cout << "console Counter-Strike version 0.1.0" << endl; }

//? This function will handle the command line arguments
void command_line_arguments(int argc, char const *argv[]) {
  //   help();
  if (argc >= 2) {
    string user_input = argv[1];
    if (user_input == "-h" || user_input == "--help") {
      help();
      exit(0);
    } else if (user_input == "-v" || user_input == "--version") {
      version();
      exit(0);
    } else {
      cout << "Invalid input, please enter -h or --help for help" << endl;
      exit(0);
    }
  }
}

//? This function will split a string into a vector of strings
vector<string> split(const string &s, char delim) {
  vector<string> result;
  stringstream ss(s);
  string item;
  while (std::getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}


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




