#include "Pair.h"
#include <iostream>

Pair::Pair(int id1, string name1, string note1, int team1, 
	   int id2, string name2, string note2, int team2) {
  pair[0] = new Person(id1, name1, note1, team1);
  pair[1] = new Person(id2, name2, note2, team2);
};

bool Pair::containsId(int id) {
  for (int i = 0; i < 2; i++) {
    if (pair[i] != NULL) {
      if (pair[i]->getId() == id) {
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

void Pair::remove(int id) {
  if (pair[0]->getId() == id) {
    pair[0] = NULL;
  }
  else {
    pair[1] = NULL;
  }
}

void Pair::printPair() {
  for (int i = 0; i < 2; i++) {
    if (pair[i] != NULL) {
      pair[i]->printPerson();
    }
    else {
      cout << "NULL" << '\n';
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

void Pair::setHasTurn(bool b) {
  hasTurn = b;
}

bool Pair::isIntact() {
  if ((pair[0] == NULL) || (pair[1] == NULL)) {
    return false;
  } 
  return true;
}

bool Pair::isUniform() {
  if (isIntact()) {
    if (pair[0]->getTeam() == pair[1]->getTeam()) {
      return true;
    }
  }
  return false;
}

