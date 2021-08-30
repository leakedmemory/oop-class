#include "OldProperty.h"

OldProperty::OldProperty() : Property() {}

OldProperty::OldProperty(string address, double value, double decrease) :
    Property(address, value), decrease(decrease) {}
