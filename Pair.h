#ifndef PAIR_H
#define PAIR_H

#include "Person.h"
#include <string>

class Pair {
  Person *pair[2];
  bool hasTurn;
public:
  Pair(int id1, string name1, string note1, int team1, 
       int id2, string name2, string note2, int team2);
  Pair(int id, string name, string note, int team);
  bool containsName(string name);
  void insert(Person *p);
  Person * remove(string Name);
  void printPair();
  void switchNotes();
  int getTurn();
  bool isIntact();
  int isSameTeam();
};

#endif

