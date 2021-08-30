#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>

using namespace std;

class Person
{
friend ostream &operator<<(ostream &, const Person &);

public:
    Person(string name) { setName(name); }

    inline string getName() const { return this->name; }
    inline void setName(string name) { this->name = name; }

protected:
    string name;
};

#endif
