#ifndef OldProperty_h
#define OldProperty_h

#include "Property.h"

class OldProperty: public Property
{
public:
    OldProperty();
    OldProperty(string, double, double);

    inline double getValue() const {
        return (this->value - this->value * this->decrease);
    }

    inline double getDecrease() { return this->decrease; }
    inline void setDecrease(double decrease) { this->decrease = decrease; }

private:
    double decrease;
};

#endif
