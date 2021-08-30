#ifndef Dog_h
#define Dog_h

#include "Animal.h"

class Dog: public Animal
{
public:
    Dog();
    Dog(string, string);

    void bark() const;
};

#endif
