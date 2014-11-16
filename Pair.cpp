#include "Pair.h"
#include <iostream>

Pair::Pair(int id1, string name1, string note1, int team1, 
	   int id2, string name2, string note2, int team2) {
  pair[0] = new Person(id1, name1, note1, team1);
  pair[1] = new Person(id2, name2, note2, team2);
};

Pair::Pair(int id, string name, string note, int team) {
  pair[0] = new Person(id, name, note, team);
  pair[1] = NULL;
};


bool Pair::containsName(string name) {
  for (int i = 0; i < 2; i++) {
    if (pair[i] != NULL) {
      if (pair[i]->getNote() == name) {
	return true;
      }
    }    
  }
  return false;
}

void Pair::insert(Person *p) {
  if (pair[0] == NULL) {
      pair[0] = p;
  }
  else {
    pair[1] = p;
  }
}

Person * Pair::remove(string name) {
  Person * p = NULL;
  if (pair[0]->getNote() == name) {
    p = pair[0];
    pair[0] = NULL;
  }
  else {
    p = pair[1];
    pair[1] = NULL;
  }
  return p;
}

void Pair::printPair() {
  for (int i = 0; i < 2; i++) {
    if (pair[i] != NULL) {
      pair[i]->printPerson();
    }
    else {
      cout << "Id: NULL" << endl << "Name: NULL" << endl << "Note: NULL" << endl << "Team: NULL" << endl;
    }
  }
}

void Pair::switchNotes() {
  if (isIntact()) {
    string temp = pair[0]->getNote();
    pair[0]->setNote(pair[1]->getNote());
    pair[1]->setNote(temp);
  }
}

int Pair::getTurn() {
  if (!isIntact()) {
    if (pair[0] != NULL) {
      return pair[0]->getTeam();
    }
    else {
      return pair[1]->getTeam();
    }
  }
  return -1;
}

bool Pair::isIntact() {
  if ((pair[0] == NULL) || (pair[1] == NULL)) {
    return false;
  } 
  return true;
}

int Pair::isSameTeam() {
  if (isIntact()) {
    if (pair[0]->getTeam() == pair[1]->getTeam()) {
      return pair[0]->getTeam();
    }
  }
  return -1;
}



