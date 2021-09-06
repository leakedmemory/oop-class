#ifndef FORMABI_H
#define FORMABI_H 

//classe abstrata

class FormaBidimensional 
{
public:
  FormaBidimensional(int numLados) : numLados(numLados) {}
  virtual ~FormaBidimensional() {}

  //método virtual puro
  virtual void desenhar() const = 0;

  virtual int calcularArea() const = 0;
  virtual int calcularPerimetro() const = 0;

protected:
  int numLados;
};

#endif
