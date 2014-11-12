#ifndef ROOM_H
#define ROOM_H

#include "Pair.h"
#include <string>


const int NO_OF_SEATS = 12;

class Room {
  Pair *pairs[NO_OF_SEATS/2];
public:
  Room();
  bool fullSofa();
  void printRoom();
  int getNameId(string s);
  int getPairIdx(int id);
  void switchNotes(int idx);
};


 
#endif
