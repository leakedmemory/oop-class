#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout;
using std::endl;

class Triangulo : public FormaBidimensional
{
public:
  Triangulo() : FormaBidimensional(3) {}

  virtual void desenhar() {
    cout << "  .   " << endl;
    cout << " / \\ " << endl;
    cout << "/   \\" << endl;
    cout << "~~~~~ " << endl;
  }
};

#endif
