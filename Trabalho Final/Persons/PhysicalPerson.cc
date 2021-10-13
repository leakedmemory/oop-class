#include "PhysicalPerson.hpp"

PhysicalPerson::PhysicalPerson(std::string name, unsigned long cpf) : Person(name) {
    this->cpf = cpf;
}

PhysicalPerson::~PhysicalPerson() {}
