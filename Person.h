#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
  int id;
  string name;
  string note;
  int team;
public:
  Person(int id, string name, string note, int team);
  void printPerson();
  void setNote(string _note);
  int getTeam();
  string getNote();
  string getName();
  int getId();
};


#endif

 
  
