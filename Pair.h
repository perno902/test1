#include "Person.h"


class Pair {
  Person *pair[2];
  bool hasTurn;
public:
  Pair();
  bool containsId(int id);
  void insert(Person *p);
  void remove(int id);
  void printPair();
  void switchNotes();
  void setHasTurn(bool);
};


