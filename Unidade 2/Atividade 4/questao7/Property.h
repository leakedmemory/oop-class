#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

using namespace std;

class Property
{
public:
    Property() {}
    Property(string address, double value);

    inline string getAddress() const { return this->address; }
    inline void setAddress(string address) { this->address = address; }

    inline double getValue() const { return this->value; }
    inline void setValue(double value) { this->value = value; }

protected:
    string address;
    double value;
};

#endif
