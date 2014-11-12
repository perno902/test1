#ifndef PAIR_H
#define PAIR_H

#include "Person.h"


class Pair {
  Person *pair[2];
  bool hasTurn;
public:
  Pair(int id1, string name1, string note1, int team1, 
       int id2, string name2, string note2, int team2);
  bool containsId(int id);
  void insert(Person *p);
  void remove(int id);
  void printPair();
  void switchNotes();
  void setHasTurn(bool);
  bool isIntact();
  bool isUniform();
};

#endif

