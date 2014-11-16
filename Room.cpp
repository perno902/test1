#include "Room.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

string nameList[NO_OF_SEATS - 1] = {"Stefan", "Aasa", "Gustav", "Alice", "Mikael", "Peter",
				    "Anna", "Jan", "Annie", "Goeran", "Carl"};

string noteList[NO_OF_SEATS];

int getTeamId(string s) {
  for (int i = 0; i <  NO_OF_SEATS/2; i++) {
    if (s == nameList[i]) {
      return 0;
    }
  }
    return 1;
}


void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void randomize (int arr[], int n) {
  srand(time(NULL));
  
  for (int i = n-1; i > 0; i--)
    {
      int j = rand() % (i+1);
      swap(&arr[i], &arr[j]);
    }
}

void scrambleNoteList() {
  int map[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(map)/sizeof(map[0]);
  
  randomize(map, n);
  
  for (int i = 0; i < NO_OF_SEATS-1; i++) {
    noteList[i] = nameList[map[i]];
  }
  
}



Room::Room() {
  int noOfPairs = NO_OF_SEATS/2;
  int nameIdx = 0;

  scrambleNoteList();



  //Creating (only intact) pairs for team 0
  for (int i = 0; i < noOfPairs-1; i++) {
    pairs[i] = new Pair(nameIdx, nameList[nameIdx], noteList[nameIdx], getTeamId(nameList[nameIdx]), 
			nameIdx+noOfPairs, nameList[nameIdx+noOfPairs], noteList[nameIdx+noOfPairs], 
			getTeamId(nameList[nameIdx+noOfPairs]));
    nameIdx++;
  }


  // Creating the last pair
  pairs[noOfPairs-1] = new Pair(nameIdx, nameList[nameIdx], noteList[nameIdx], getTeamId(nameList[nameIdx]));

}


bool Room::isName(string s) {
  for (int i = 0; i < NO_OF_SEATS - 1; i++) {
    if (nameList[i] == s) {
      return true;
    }
  }
  return false;
}

bool Room::isSolo(string s) {
  if (pairs[getNullPairIdx()]->containsName(s)) {
    return true;
  }
  return false;
}

int Room::fullSofa() {
  int a = pairs[0]->isSameTeam();
  int b = pairs[1]->isSameTeam();
  if ((a>=0) && (b>=0) && (a==b)) {
    return a;
  }
  return -1;
}

int Room::getTurn() {
  for (int i = 0; i < NO_OF_SEATS/2; i++) {
    if (!pairs[i]->isIntact()) {
      return pairs[i]->getTurn();
    }
  }
}

void Room::printRoom() {
  cout << "______________________%% SOFFAN %% _____________________" << endl;
  
  pairs[0]->printPair();
  pairs[1]->printPair();

  cout << "________________________________________________________" << endl; 
  
  
  for (int i = 2; i < NO_OF_SEATS/2; i++) {
    pairs[i]->printPair();
    cout << "--------------------------------" << endl;
  }
}


/*
int Room::getNameId(string s) {
  for (int i = 0; i < NO_OF_SEATS; i++) {
    if (s == nameList[i]) {
      return i;
    }
  }
  return -1;
}
*/

int Room::getPairIdx(string name) {
  for (int i = 0; i < NO_OF_SEATS/2; i++) {
    if (pairs[i]->containsName(name)) {
      return i;
    }
  }
  return -1;
}

int Room::getNullPairIdx() {
  for (int i = 0; i < NO_OF_SEATS/2; i++) {
    if (!pairs[i]->isIntact()) {
      return i;
    }
  }
}

void Room::switchNotes(int idx) {
  pairs[idx]->switchNotes(); 
}


void Room::callName(string name) {
  int oldIdx = getPairIdx(name);
  int newIdx = getNullPairIdx();

  Person * p = pairs[oldIdx]->remove(name);

  pairs[newIdx]->insert(p);
  switchNotes(newIdx);
}
