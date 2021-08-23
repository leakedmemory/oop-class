#include <iostream>
#include "Complex.h"

using namespace std;

ostream &operator<<(ostream &out, const Complex &number) {
    out << number.real << ((number.imaginary >= 0) ? "+" : "");
    out << number.imaginary << "i" << endl;

    return out;
}

Complex::Complex(double a, double b) {
    real = a;
    imaginary = b;
}

Complex Complex::operator+(const Complex &number) const {
    double a = this->real + number.real;
    double b = this->imaginary + number.imaginary;

    Complex result(a, b);
    return result;
}

void Complex::operator+=(const Complex &number) {
    this->real += number.real;
    this->imaginary += number.imaginary;
}

Complex &Complex::operator++() {
    this->real += 1;
    return *this;
}

Complex Complex::operator++(int) {
    Complex tmp = *this;
    this->real += 1;

    return tmp;
}
