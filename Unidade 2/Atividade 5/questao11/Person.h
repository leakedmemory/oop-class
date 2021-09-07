#ifndef Person_h
#define Person_h

#include <string>

using namespace std;

class Person
{
public:
    Person(string, string, string);
    virtual ~Person() {}

    virtual inline string getName() const { return this->name; }
    virtual inline void setName(string name) { this->name = name; }

    virtual inline string getAddress() const { return this->address; }
    virtual inline void setAddress(string address) { this->address = address; }

    virtual inline string getEmail() const { return this->email; }
    virtual inline void setEmail(string email) { this->email = email; }

protected:
    string name;
    string address;
    string email;
};

#endif
