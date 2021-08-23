#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex
{
friend ostream &operator<<(ostream &, const Complex &);

public:
    Complex(double a=0, double b=1);

    // Operadores de soma
    Complex operator+(const Complex &) const;
    void operator+=(const Complex &);
    Complex &operator++();
    Complex operator++(int);

    // Operadores de subtração
    Complex operator-(const Complex &) const;
    void operator-=(const Complex &);
    Complex &operator--();
    Complex operator--(int);

private:
    double real;
    double imaginary;
};

#endif
