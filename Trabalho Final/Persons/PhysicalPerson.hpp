#ifndef PhysicalPerson_hpp
#define PhysicalPerson_hpp

#include "Person.hpp"
#include <string>

class PhysicalPerson: public Person
{
public:
    PhysicalPerson(std::string, unsigned long);
    ~PhysicalPerson() override;

private:
    unsigned long cpf;
};

#endif
