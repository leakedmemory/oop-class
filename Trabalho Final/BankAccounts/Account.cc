#include <sstream>

#include "Account.hpp"
#include "Exceptions/InvalidPaymentMethodError.hpp"
#include "Exceptions/InsufficientFundsError.hpp"

void operator<<(Account& account, double value) {
    account.balance += value;
}

Account::Account(unsigned accountNumber, Person* owner, double balance) {
    this->accountNumber = accountNumber;
    this->owner = owner;
    this->balance = balance;
}

Account::~Account() {}

std::string Account::getDate() const {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    unsigned day = ltm->tm_mday;
    unsigned month = 1 + ltm->tm_mon;
    unsigned year = 1900 + ltm->tm_year;

    std::ostringstream oss;
    oss << day << "/" << month << "/" << year;
    return oss.str();
}

void Account::logError(std::exception& e) {
    std::cout << e.what() << std::endl;
}

void Account::makePayment(double value, const std::string& type) {
    try {
        paymentWithCardOrDebit(value, type);
    } catch(std::exception& e) {
        logError(e);
    }
}

void Account::paymentWithCardOrDebit(double value, const std::string& type) {
    if (type != "credito" && type != "debito") {
        throw InvalidPaymentMethodError();
    }

    this->makePaymentWithCardOrDebit(value, type);
}

void Account::makePaymentWithCardOrDebit(double value, const std::string& type) {
    if (type == "debito") {
        this->debitPayment(value);
    } else {
        this->cardPayment(value);
    }
}

void Account::debitPayment(double value) {
    if (this->balance - value < 0) {
        throw InsufficientFundsError();
    }

    this->balance -= value;
    // Implementar transação
}

void Account::cardPayment(double value) {
    // Implementar transação
}

void Account::transfer(Account& destination, double value) {
    try {
        transferMoney(destination, value);
    } catch(std::exception& e) {
        logError(e);
    }
}

void Account::transferMoney(Account& destination, double value) {
    canTransfer(value);

    this->balance -= value;
    destination.balance += value;
    // Implementar transação NAS DUAS CONTAS
}

void Account::canTransfer(double value) {
    if (this->balance - value < 0) {
        throw InsufficientFundsError();
    }
}

unsigned Account::getAccountNumber() const {
    return this->accountNumber;
}

std::string Account::getOwnersName() const {
    return this->owner->getName();
}

double Account::getBalance() const {
    return this->balance;
}
