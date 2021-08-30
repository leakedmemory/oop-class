#ifndef Cat_h
#define Cat_h

#include "Animal.h"

class Cat: public Animal
{
public:
    Cat();
    Cat(string, string);

    void meow() const;
};

#endif
