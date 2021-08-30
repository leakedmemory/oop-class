#include <iostream>
#include "Cat.h"

Cat::Cat() : Animal() {}

Cat::Cat(string name, string breed) : Animal(name, breed) {}

void Cat::meow() const {
    cout << this->name << " miou." << endl;
}
