#include "LegalPerson.h"

LegalPerson::LegalPerson(
    string name, unsigned long CNPJ, string socialReason
) : Person(name), CNPJ(CNPJ), socialReason(socialReason) {}
