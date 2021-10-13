#ifndef CheckingAccountWithLimit_hpp
#define CheckingAccountWithLimit_hpp

#include "RegularCheckingAccount.hpp"

class CheckingAccountWithLimit: public RegularCheckingAccount
{
public:
    CheckingAccountWithLimit(unsigned, Person*, double=0, double=300);
    ~CheckingAccountWithLimit() final;

    // virtual void seeStatement() const = 0;

private:
    double actual_limit;
    double fixed_limit;

    void debitPayment(double) final;
    void makeDebitPayment(double);
    void debitWithLimit(double);
    void transferMoney(Account&, double) final;
    void canTransfer(double) final;
};

#endif
