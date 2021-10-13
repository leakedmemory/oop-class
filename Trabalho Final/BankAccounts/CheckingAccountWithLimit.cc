#include "CheckingAccountWithLimit.hpp"
#include "Exceptions/InsufficientFundsError.hpp"
#include "Exceptions/LimitExceededError.hpp"

CheckingAccountWithLimit::CheckingAccountWithLimit(
    unsigned accountNumber, Person* owner, double balance, double limit
) : RegularCheckingAccount(accountNumber, owner, balance) {
    this->fixed_limit = limit;
}

CheckingAccountWithLimit::~CheckingAccountWithLimit() {}

void CheckingAccountWithLimit::debitPayment(double value) {
    if (this->balance + this->actual_limit - value < 0) {
        throw InsufficientFundsError();
    } 

    this->makeDebitPayment(value);

    // Implementar transação
}

void CheckingAccountWithLimit::makeDebitPayment(double value) {
    if (this->balance - value >= 0) {
        this->balance -= value;
    } else {
        this->debitWithLimit(value);
    }
}

void CheckingAccountWithLimit::debitWithLimit(double value) {
    double difference = value - this->balance;
    this->balance -= difference;
    this->actual_limit -= value - difference;
}

void CheckingAccountWithLimit::transferMoney(Account& destination, double value) {

}

void CheckingAccountWithLimit::canTransfer(double) {

}
