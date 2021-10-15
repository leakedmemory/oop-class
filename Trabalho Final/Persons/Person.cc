#include "Person.hpp"

Person::Person(std::string name) {
    this->name = name;
}

Person::~Person() {}

void Person::setName(std::string name) {
    this->name = name;
}

std::string Person::getName() const {
    return this->name;
}
