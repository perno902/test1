#include "Person.h"
#include <iostream>

Person::Person (int _id, string _name, string _note , int _team) {
  id = _id;
  name = _name;
  note = _note;
  team = _team;
}

void Person::printPerson() {
  cout << "Id: " << id << '\n';
  cout << "Name: " << name << '\n';
  cout << "Note: " << note << '\n';
  cout << "Team: " << team << '\n';
}

void Person::setNote(string _note) {note = _note;};

string Person::getNote() {return note;};

int Person::getTeam() {return team;}

string Person::getName() {return name;};

int Person::getId() {return id;};


