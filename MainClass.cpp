#include "Person.h"
#include "Pair.h"
#include "Room.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  //Person *p1 = new Person(3, "Glinda", "Glinda", 0);
  //Person *p2 = new Person(4, "Elphaba", "Elphaba", 1);

  //switchNotes (p1, p2);
  //p1->printPerson();
  //p2->printPerson();

  //Pair *pair = new Pair(3, "Glinda", "Glinda", 0, 4, "Elphaba", "Elphaba", 1);
  
  //Insert and remove tests
  //pair->printPair();
  //pair->containsId(3);
  //pair->containsId(4);  
  // pair->remove(4);
  //pair->printPair();
  //pair->containsId(4);

  //pair->switchNotes();
  //pair->printPair();
  
  Room *room = new Room();
  

  
  room->printRoom();

  int p = room->getPairIdx(room->getNameId("Carl"));

  room->switchNotes(p);
  room->printRoom();


  return 0;
}



