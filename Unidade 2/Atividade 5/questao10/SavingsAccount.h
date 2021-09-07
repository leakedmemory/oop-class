#ifndef SavingsAccount_h
#define SavingsAccount_h

#include "BankAccount.h"

class SavingsAccount: public BankAccount
{
public:
    SavingsAccount(unsigned accountNumber, string name, int day) :
        BankAccount(accountNumber, name), anniversaryDay(day) {}

    virtual void statement() const;

private:
    int anniversaryDay;
};

#endif
