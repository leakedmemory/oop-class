#ifndef SavingsAccount_hpp
#define SavingsAccount_hpp

#include "Account.hpp"

unsigned short inline getPresentDay() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    unsigned day = ltm->tm_mday;

    return day;
}

class SavingsAccount: public Account
{
public:
    SavingsAccount(unsigned, Person*, double=0, unsigned short=getPresentDay());
    ~SavingsAccount() final;

    // void seeStatement() const final;

private:
    unsigned short anniversaryDay;
};

#endif
