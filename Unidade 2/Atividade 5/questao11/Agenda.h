#ifndef Agenda_h
#define Agenda_h

#include "Person.h"

class Agenda
{
public:
    ~Agenda();

    void addPerson(string);
    void addPerson(Person *);
    void removePerson(string);
    void updatePerson(string);

    void listContacts() const;

private:
    Person *contacts[6];
    unsigned numberOfContacts;
};

#endif
