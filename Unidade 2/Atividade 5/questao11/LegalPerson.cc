#include "LegalPerson.h"

LegalPerson::LegalPerson(
    string name,
    string address,
    string email,
    unsigned long CNPJ,
    unsigned long stateRegistration,
    string socialReason
) : Person(name, address, email), CNPJ(CNPJ),
    stateRegistration(stateRegistration), socialReason(socialReason) {}
