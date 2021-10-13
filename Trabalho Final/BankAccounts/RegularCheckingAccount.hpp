#ifndef RegularCheckingAccount_hpp
#define RegularCheckingAccount_hpp

#include "Account.hpp"

class RegularCheckingAccount: public Account
{
public:
    RegularCheckingAccount(unsigned, Person*, double=0);
    ~RegularCheckingAccount() override;

    // virtual void seeStatement() const = 0;
};

#endif
