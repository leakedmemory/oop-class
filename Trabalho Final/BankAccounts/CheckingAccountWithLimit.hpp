#ifndef CheckingAccountWithLimit_hpp
#define CheckingAccountWithLimit_hpp

#include "RegularCheckingAccount.hpp"

class CheckingAccountWithLimit: public RegularCheckingAccount
{
    friend void operator>>(CheckingAccountWithLimit&, double);

public:
    CheckingAccountWithLimit(unsigned, Person*, double=0, double=300);
    ~CheckingAccountWithLimit() final;

    double getLimit() const;

private:
    double limit;

    void withdraw(double) final;
};

#endif
