#include "Room.h"
#include <iostream>

string nameList[NO_OF_SEATS] = {"Stefan", "Åsa", "Gustav", "Alice", "Mikael", "Peter",
		     "Anna", "Jan", "Annie", "Göran", "Erik", "Carl"};

Room::Room() {
  for (int i = 0; i < NO_OF_SEATS/2; i = i+2) {
    pairs[i/2] = new Pair(i, nameList[i], nameList[i], 0, i+1, nameList[i+1], nameList[i+1], 0);
  }
  for (int i = NO_OF_SEATS/2; i < NO_OF_SEATS; i = i+2) {
    pairs[i/2] = new Pair(i, nameList[i], nameList[i], 1, i+1, nameList[i+1], nameList[i+1], 1);
  }
}


bool Room::fullSofa() {
  if (pairs[0]->isUniform() && pairs[1]->isUniform()) {
    return true;
  }
  return false;
}

void Room::printRoom() {
  for (int i = 0; i < NO_OF_SEATS/2; i++) {
    pairs[i]->printPair();
    cout << '\n';
  }
}

int Room::getNameId(string s) {
  for (int i = 0; i < NO_OF_SEATS; i++) {
    if (s == nameList[i]) {
      return i;
    }
  }
  return -1;
}

int Room::getPairIdx(int id) {
  for (int i = 0; i < NO_OF_SEATS/2; i++) {
    if (pairs[i]->containsId(id)) {
      return i;
    }
  }
  return -1;
}

void Room::switchNotes(int idx) {
  pairs[idx]->switchNotes(); 
}
