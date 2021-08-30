#include "LegalPerson.h"

LegalPerson::LegalPerson(
    string name, unsigned long int CNPJ, string socialReason
) : Person(name), CNPJ(CNPJ), socialReason(socialReason) {}
