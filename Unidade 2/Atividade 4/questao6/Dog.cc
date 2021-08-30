#include "iostream"
#include "Dog.h"

Dog::Dog() : Animal() {}

Dog::Dog(string name, string breed) : Animal(name, breed) {}

void Dog::bark() const {
    cout << this->name << " latiu." << endl;
}
