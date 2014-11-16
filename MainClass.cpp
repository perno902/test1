#include "Person.h"
#include "Pair.h"
#include "Room.h"
#include <iostream>
#include <string>
using namespace std;


string input;
string lastValid;
bool gameWon = false;

void getNameStr(Room * r) {
  bool validInput;
  
  while (not validInput) {
    cin >> input;
 
    if (r->isName(input)) {
      if (input == lastValid) {
	cout << "Names can not be called twice in a row! Please try again." << endl;
      }
      else if (r->isSolo(input)) {
	cout << "You can not call the name written on your own note. Please try again!" << endl;
      }
      else {
	validInput = true;
      }
    }
    else {
      cout << "Invalid name! Please try again." << endl;
    }
  }
  lastValid = input;
}




int main() {
  
  Room *room = new Room();
  

  // Game main loop:
  while (not gameWon) {
    room->printRoom();  
    
    cout << "===================================================" << endl;;
    cout << "Team " << room->getTurn() << ", please enter a name." << endl;
    getNameStr(room);
    
    room->callName(input);
    
    if (room->fullSofa() >= 0) {
      gameWon = true;
    }
  }
  
  cout << "Team " << room->fullSofa() << " won and get to govern the country!";

    
  return 0;
}



