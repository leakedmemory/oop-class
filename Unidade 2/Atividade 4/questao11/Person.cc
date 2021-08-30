#include "Person.h"

ostream &operator<<(ostream &out, const Person &person) {
    out << person.getName() << endl;

    return out;
}
