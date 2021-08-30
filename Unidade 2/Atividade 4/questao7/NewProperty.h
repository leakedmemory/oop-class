#ifndef NewProperty_h
#define NewProperty_h

#include "Property.h"

class NewProperty: public Property
{
public:
    NewProperty();
    NewProperty(string, double, double);

    inline double getValue() const {
        return (this->value + this->value * this->addition);
    }

    inline double getAddition() { return this->addition; }
    inline void setAddition(double addition) { this->addition = addition; }

private:
    double addition;
};

#endif
