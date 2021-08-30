#include "LegalPerson.h"

LegalPerson::LegalPerson(
    string socialReason, unsigned long int CNPJ, string name
) : Person(name), CNPJ(CNPJ), name(name) {}
