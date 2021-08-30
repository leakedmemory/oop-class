#ifndef PhysicalPerson_h
#define PhysicalPerson_h

#include "Person.h"

class PhysicalPerson: public Person
{
public:
    PhysicalPerson(string, unsigned long int);

    inline unsigned long int getCPF() const { return this->CPF; } 
    inline void setCPF(unsigned long int CPF) { this->CPF = CPF; }

private:
    string name;
    unsigned long int CPF;
};

#endif
