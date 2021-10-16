#include "LegalPerson.hpp"

LegalPerson::LegalPerson(std::string name, unsigned long cnpj) : Person(name) {
    this->cnpj = cnpj;
}

LegalPerson::~LegalPerson() {}

unsigned long LegalPerson::getCNPJ() const {
    return this->cnpj;
}
