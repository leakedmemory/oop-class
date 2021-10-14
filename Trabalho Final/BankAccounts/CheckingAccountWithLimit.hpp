#ifndef CheckingAccountWithLimit_hpp
#define CheckingAccountWithLimit_hpp

#include "RegularCheckingAccount.hpp"

class CheckingAccountWithLimit: public RegularCheckingAccount
{
    friend void operator>>(CheckingAccountWithLimit&, double);

public:
    CheckingAccountWithLimit(unsigned, Person*, double=0, double=300);
    ~CheckingAccountWithLimit() final;

    // virtual void seeStatement() const = 0;
    double getLimit() const;

private:
    double limit;

    void debitPayment(double) final;
    void withdraw(double) final;
};

#endif
