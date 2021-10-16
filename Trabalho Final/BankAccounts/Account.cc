#include <iostream>
#include <sstream>
#include <iomanip>

#include "Account.hpp"
#include "Exceptions/InvalidPaymentMethodError.hpp"
#include "Exceptions/InsufficientFundsError.hpp"

void operator<<(Account& account, double value) {
    account.balance += value;
    account.addTransaction(value, "deposito");
}

void operator>>(Account& account, double value) {
    try {
        account.withdraw(value);
        account.addTransaction(value, "retirada");
    } catch(std::exception& e) {
        account.logError(e);
    }
}

Account::Account(unsigned accountNumber, Person* owner, double balance) {
    this->accountNumber = accountNumber;
    this->owner = owner;
    this->balance = (balance >= 0) ? balance : 0;
}

Account::~Account() {}

void Account::withdraw(double value) {
    if (this->balance - value < 0) {
        throw InsufficientFundsError();
    }

    this->balance -= value;
}

std::string Account::getActualDate() const {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    unsigned day = ltm->tm_mday;
    unsigned month = 1 + ltm->tm_mon;
    unsigned year = 1900 + ltm->tm_year;

    std::ostringstream oss;
    oss << day << "/" << month << "/" << year;
    return oss.str();
}

void Account::logError(std::exception& e) const {
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
    } else if (type == "debito") {
        this->debitPayment(value);
    } else {
        this->cardPayment(value);
    }
}

void Account::debitPayment(double value) {
    this->withdraw(value);
    this->addTransaction(value, "debito");
}

void Account::cardPayment(double value) {
    this->addTransaction(value, "credito");
}

void Account::transfer(Account& destination, double value) {
    try {
        transferMoney(destination, value);
    } catch(std::exception& e) {
        logError(e);
    }
}

void Account::transferMoney(Account& destination, double value) {
    this->withdraw(value);
    destination.balance += value;

    this->addTransaction(value, "transferência");
    destination.addTransaction(value, "recebido");
}

void Account::addTransaction(double value, const std::string& type) {
    std::ostringstream oss;
    oss << this->getActualDate() << "-" << value << "-" << type;

    this->transactions.push_back(oss.str());
}

unsigned short Account::getTransactionsSize() const {
    unsigned short transactions = (
        (this->transactions.size() < 30) ? this->transactions.size() : 30
    );

    return transactions;
}

void Account::printLast30Transactions() const {
    unsigned short size = this->getTransactionsSize();
    for (unsigned short i = 0, k = this->transactions.size() - size; i < size; i++, k++) {
        std::cout << this->transactions[k] << std::endl;
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

Person* Account::getOwner() const {
    return this->owner;
}

void Account::setAccountNumber(unsigned number) {
    this->accountNumber = number;
}

void Account::setOwnersName(std::string name) {
    this->owner->setName(name);
}

std::vector<std::string>* Account::getTransactions() {
    return &this->transactions;
}
