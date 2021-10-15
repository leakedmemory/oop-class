#include <iostream>

#include "CheckingAccountWithLimit.hpp"
#include "Exceptions/InsufficientFundsError.hpp"
#include "Exceptions/LimitExceededError.hpp"

void operator>>(CheckingAccountWithLimit& account, double value) {
    try {
        account.withdraw(value);
        account.addTransaction(value, "retirada");
    } catch(std::exception& e) {
        account.logError(e);
    }
}

CheckingAccountWithLimit::CheckingAccountWithLimit(
    unsigned accountNumber, Person* owner, double limit, double balance
) : RegularCheckingAccount(accountNumber, owner, balance) {
    this->limit = (limit > 0) ? -limit : -300;
}

CheckingAccountWithLimit::~CheckingAccountWithLimit() {}

void CheckingAccountWithLimit::withdraw(double value) {
    if (this->balance - value < limit) {
        throw LimitExceededError();
    }

    this->balance -= value;
}

double CheckingAccountWithLimit::getLimit() const {
    return -this->limit;
}
