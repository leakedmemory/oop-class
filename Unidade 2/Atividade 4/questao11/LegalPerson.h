#ifndef LegalPerson_h
#define LegalPerson_h

#include "Person.h"

class LegalPerson: public Person
{
public:
    LegalPerson(string, unsigned long, string);

    inline string getName() const { return this->name; }
    inline void setName(string name) { this->name = name; }

    inline unsigned long getCNPJ() const { return this->CNPJ; } 
    inline void setCNPJ(long int CNPJ) { this->CNPJ = CNPJ; }

    inline string getSocialReason() const { return this->socialReason; }
    inline void setSocialReason(string socialReason) {
        this->socialReason = socialReason;
    }

protected:
    string socialReason;
    unsigned long CNPJ;
    string name;
};

#endif
