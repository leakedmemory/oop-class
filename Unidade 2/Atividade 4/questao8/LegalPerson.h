#ifndef LegalPerson_h
#define LegalPerson_h

#include "Person.h"

class LegalPerson: public Person
{
public:
    LegalPerson(string, unsigned long int, string);

    inline string getName() const { return this->name; }
    inline void setName(string name) { this->name = name; }

    inline unsigned long int getCNPJ() const { return this->CNPJ; } 
    inline void setCNPJ(long int CNPJ) { this->CNPJ = CNPJ; }

    inline string getSocialReason() const { return this->socialReason; }
    inline void setSocialReason(string socialReason) {
        this->socialReason = socialReason;
    }

private:
    string socialReason;
    unsigned long int CNPJ;
    string name;
};

#endif
