#ifndef Animal_h
#define Animal_h

#include <string>

using namespace std;

class Animal
{
public:
    Animal();
    // coloquei a raça também aqui, já que não estava sendo usada pra nada no UML.
    Animal(string, string);

    void walk() const;

protected:
    string name;
    string breed;
};

#endif
