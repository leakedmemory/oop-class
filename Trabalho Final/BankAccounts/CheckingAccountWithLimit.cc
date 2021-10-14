#include "CheckingAccountWithLimit.hpp"
#include "Exceptions/InsufficientFundsError.hpp"
#include "Exceptions/LimitExceededError.hpp"

void operator>>(CheckingAccountWithLimit& account, double value) {
    try {
        account.withdraw(value);
        // Implementar retirada
    } catch(std::exception& e) {
        account.logError(e);
    }
}

CheckingAccountWithLimit::CheckingAccountWithLimit(
    unsigned accountNumber, Person* owner, double balance, double limit
) : RegularCheckingAccount(accountNumber, owner, balance) {
    this->limit = limit * -1;
}

CheckingAccountWithLimit::~CheckingAccountWithLimit() {}

void CheckingAccountWithLimit::withdraw(double value) {
    if (this->balance - value < limit) {
        throw LimitExceededError();
    }

    this->balance -= value;
}

void CheckingAccountWithLimit::debitPayment(double value) {
    this->withdraw(value);
    // Implementar transação
}

double CheckingAccountWithLimit::getLimit() const {
    return this->limit * -1;
}
