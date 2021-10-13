#include "Person.hpp"

Person::Person(std::string name) {
    this->name = name;
}

Person::~Person() {}

std::string Person::getName() const {
    return this->name;
}
