#include "NewProperty.h"

NewProperty::NewProperty() : Property() {}

NewProperty::NewProperty(string address, double value, double addition) :
    Property(address, value), addition(addition) {}
