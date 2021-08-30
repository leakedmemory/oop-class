#ifndef Client_h
#define Client_h

#include "PhysicalPerson.h"

class Client: public PhysicalPerson
{
friend ostream &operator<<(ostream &, const Client &);

public:
    Client();
    Client(string, unsigned long, unsigned long, string);

    inline unsigned long getPhoneNumber() const {
        return this->phoneNumber;
    }
    inline void setPhoneNumber(unsigned long number) {
        this->phoneNumber = number;
    }

    inline string getAddress() const { return this->address; }
    inline void setAddress(string address) { this->address = address; }

private:
    unsigned long phoneNumber;
    string address;
};

#endif
