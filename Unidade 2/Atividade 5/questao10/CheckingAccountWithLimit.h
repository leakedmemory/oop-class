#ifndef AccountWithLimit_h
#define AccountWithLimit_h

#include "BankAccount.h"

class CheckingAccountWithLimit: public BankAccount
{
public:
    CheckingAccountWithLimit(
        unsigned accountNumber, string name, double limit
) : BankAccount(accountNumber, name), limit(limit), FIXED_LIMIT(limit) {}

    virtual void deposit(double);
    virtual void withdraw(double);
    virtual void statement() const;

private:
    double limit;
    double FIXED_LIMIT;
};

#endif
