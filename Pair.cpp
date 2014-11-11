#include "Pair.h"
#include <iostream>

Pair::Pair() {
  pair[0] = NULL;
  pair[1] = NULL;
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
      //  pair[0]->printPerson();
  }
  else {
    pair[1] = p;
    //  pair[1]->printPerson();
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
  }
}

void Pair::switchNotes() {
  string temp = pair[0]->getNote();
  pair[0]->setNote(pair[1]->getNote());
  pair[1]->setNote(temp);
}

void Pair::setHasTurn(bool b) {
  hasTurn = b;
}

