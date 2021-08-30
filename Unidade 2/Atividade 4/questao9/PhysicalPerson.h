#ifndef PhysicalPerson_h
#define PhysicalPerson_h

#include "Person.h"

class PhysicalPerson: public Person
{
public:
    PhysicalPerson(string, unsigned long);
    
    inline unsigned long getCPF() const { return this->CPF; } 
    inline void setCPF(unsigned long CPF) { this->CPF = CPF; }

protected:
    string name;
    unsigned long CPF;
};

#endif
