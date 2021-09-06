#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>

#include "FormaBidimensional.h"

using namespace std;

class Circulo : public FormaBidimensional
{
public:
  Circulo(int raio) : FormaBidimensional(99999), raio(raio) {}

  virtual void desenhar() const {
    cout << "  _ " << endl;
    cout << "/   \\" << endl;
    cout << "\\   /" << endl;
    cout << "  ~ " << endl;
  }

  virtual int calcularArea() const {
      return PI * raio * raio;
  }

  virtual int calcularPerimetro() const {
      return 2 * PI * raio;
  }

private:
    const int PI = 3;
    int raio;
};

#endif
