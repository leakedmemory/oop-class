#include <sstream>

#include "Account.hpp"

Account::Account(unsigned accountNumber, Person &owner) {
    this->accountNumber = accountNumber;
    this->owner = &owner;
}

Account::~Account() {
    delete owner;
}

void Account::payment(double value, const std::string &type) {
    if (type == "credito") {
        this->cardPayment(value);
    } else if (type == "debito") {
        this->debitPayment(value);
    } else {
        // Implementar tratamento de erro
    }
}

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

void Account::cardPayment(double value) {
    std::string date = getDate();
    
    // Implementar transação e tratamento de erro
}

void Account::debitPayment(double value) {
    if (this->balance - value >= 0) {
        this->balance -= value;

        std::string date = getDate();

        // Implementar transação e tratamento de erro
    }
}
