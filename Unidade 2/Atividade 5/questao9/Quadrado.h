#ifndef QUADRADO_H
#define QUADRADO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout;
using std::endl;

class Quadrado : public FormaBidimensional
{
public:
  Quadrado() : FormaBidimensional(4) {}

  virtual void desenhar() {
    cout << "-----" << endl;
    cout << "|   |" << endl;
    cout << "-----" << endl;
  }
};

#endif
