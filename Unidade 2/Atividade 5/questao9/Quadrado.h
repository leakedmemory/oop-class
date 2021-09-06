#ifndef QUADRADO_H
#define QUADRADO_H

#include <iostream>

#include "FormaBidimensional.h"

using namespace std;

class Quadrado : public FormaBidimensional
{
public:
  Quadrado(int lado) : FormaBidimensional(4), lado(lado) {}

  virtual void desenhar() const {
    cout << "-----" << endl;
    cout << "|   |" << endl;
    cout << "-----" << endl;
  }

  virtual int calcularArea() const {
      return lado * lado;
  }

  virtual int calcularPerimetro() const {
      return lado * this->numLados;
  }

private:
    int lado;
};

#endif
