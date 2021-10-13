#ifndef LegalPerson_hpp
#define LegalPerson_hpp

#include "Person.hpp"
#include <string>

class LegalPerson: public Person
{
public:
    LegalPerson(std::string, unsigned long);
    ~LegalPerson() final;

private:
    unsigned long cnpj;
};

#endif
