#ifndef ROOM_H
#define ROOM_H

#include "Pair.h"
#include <string>


const int NO_OF_SEATS = 12;

class Room {
  Pair *pairs[NO_OF_SEATS/2];
public:
  Room();
  bool isName(string s);
  bool isSolo(string s);
  int fullSofa();
  int getTurn();
  void printRoom();
  int getNameId(string s);
  int getPairIdx(string name);
  int getNullPairIdx();
  void switchNotes(int idx);
  void callName(string name);
};


 
#endif
