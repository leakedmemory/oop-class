#ifndef RegCheckingAccount_h
#define RegChechkingAccount_h

#include "BankAccount.h"

class RegCheckingAccount: public BankAccount
{
public:
    RegCheckingAccount(unsigned accountNumber, string name) :
        BankAccount(accountNumber, name) {}

    virtual void statement() const;
};

#endif
