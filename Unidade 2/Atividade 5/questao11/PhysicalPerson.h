#ifndef PhysicalPerson_h
#define PhysicalPerson_h

#include "Person.h"

class PhysicalPerson: public Person
{
public:
    PhysicalPerson(string, string, string, unsigned long, string, string);

    inline unsigned long getCPF() const { return this->CPF; }
    inline void setCPF(unsigned long CPF) { this->CPF = CPF; }

    inline string getDateOfBirth() const { return this->dateOfBirth; }
    inline void setDateOfBirth(string dateOfBirth) {
        this->dateOfBirth = dateOfBirth;
    }

    inline string getMaritalStatus() const { return this->maritalStatus; }
    inline void setMaritalStatus(string maritalStatus) {
        this->maritalStatus = maritalStatus;
    }

private:
    unsigned long CPF;
    string dateOfBirth;
    string maritalStatus;
};

#endif
