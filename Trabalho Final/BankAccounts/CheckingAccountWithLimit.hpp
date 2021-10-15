#ifndef CheckingAccountWithLimit_hpp
#define CheckingAccountWithLimit_hpp

#include "RegularCheckingAccount.hpp"

class CheckingAccountWithLimit: public RegularCheckingAccount
{
    friend void operator>>(CheckingAccountWithLimit&, double);

public:
    CheckingAccountWithLimit(unsigned, Person*, double, double=0);
    ~CheckingAccountWithLimit() final;

    double getLimit() const;

private:
    double limit;

    void withdraw(double) final;
};

#endif
