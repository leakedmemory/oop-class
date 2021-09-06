#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <iostream>
#include <math.h>

#include "FormaBidimensional.h"

using namespace std;

class Triangulo : public FormaBidimensional
{
public:
  Triangulo(int lado) : FormaBidimensional(3), lado(lado), base(lado/2) {
      this->altura = static_cast <int> (lado * sqrt(3) / 2);
  }

  virtual void desenhar() const {
    cout << "  .   " << endl;
    cout << " / \\ " << endl;
    cout << "/   \\" << endl;
    cout << "~~~~~ " << endl;
  }

  virtual int calcularArea() const {
      return base * altura / 2;
  }

  virtual int calcularPerimetro() const {
      return lado * this->numLados;
  }

private:
    int lado;
    int base;
    int altura;
};

#endif
