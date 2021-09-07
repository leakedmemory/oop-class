#include "PhysicalPerson.h"

PhysicalPerson::PhysicalPerson(
    string name,
    string address,
    string email,
    unsigned long CPF,
    string dateOfBirth,
    string maritalStatus
) : Person(name, address, email), CPF(CPF), dateOfBirth(dateOfBirth),
    maritalStatus(maritalStatus) {}
