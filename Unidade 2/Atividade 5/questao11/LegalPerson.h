#ifndef LegalPerson_h
#define LegalPerson_h

#include "Person.h"

class LegalPerson: public Person
{
public:
    LegalPerson(string, string, string, unsigned long, unsigned long, string);

    inline unsigned long getCNPJ() const { return this->CNPJ; }
    inline void setCNPJ(unsigned long CNPJ) { this->CNPJ = CNPJ; }

    inline unsigned long getStateRegistration() const {
        return this->stateRegistration;
    }
    inline void setStateRegistration(unsigned long stateRegistration) {
        this->stateRegistration = stateRegistration;
    }

    inline string getSocialReason() const { return this->socialReason; }
    inline void setSocialReasion(string socialReason) {
        this->socialReason = socialReason;
    }

private:
    unsigned long CNPJ;
    unsigned long stateRegistration;
    string socialReason;
};

#endif
