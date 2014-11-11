#include "Person.h"
#include "Pair.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  Person *p1 = new Person(3, "Glinda", "Glinda", 0);
  Person *p2 = new Person(4, "Elphaba", "Elphaba", 1);

  //switchNotes (p1, p2);
  //p1->printPerson();
  //p2->printPerson();

  Pair *pair = new Pair();
  
  //Insert and remove tests
  pair->insert(p1);
  pair->insert(p2);
  pair->printPair();
  pair->containsId(3);
  pair->containsId(4);  
  // pair->remove(4);
  //pair->printPair();
  //pair->containsId(4);

  pair->switchNotes();
  pair->printPair();
  

  return 0;

}



