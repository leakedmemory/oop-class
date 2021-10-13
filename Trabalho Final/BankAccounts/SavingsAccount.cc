#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(
    unsigned accountNumber, Person* owner, double balance, unsigned short anniversaryDay
) : Account(accountNumber, owner, balance) {
    this->anniversaryDay = anniversaryDay;
}

SavingsAccount::~SavingsAccount() {}
