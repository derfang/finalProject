#include "additional_functions.h"
#include "WeaponAndListOfWeapon.h"
#include "PlayerAndList.h"

#include <bits/stdc++.h>
using namespace std;

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