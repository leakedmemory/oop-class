#include <iostream>
#include "Animal.h"

Animal::Animal() {
    this->name = "Bichinho";
    this->breed = "Vira-lata";
}

Animal::Animal(string name, string breed) {
    this->name = name;
    this->breed = breed;
}

void Animal::walk() const {
    cout << this->name << " caminhou." << endl;
}
