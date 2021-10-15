#include <iostream>

#include "RegularCheckingAccount.hpp"

RegularCheckingAccount::RegularCheckingAccount(
    unsigned accountNumber, Person* owner, double balance
) : Account(accountNumber, owner, balance) {}

RegularCheckingAccount::~RegularCheckingAccount() {}

void RegularCheckingAccount::seeStatement() const {
    std::cout << "Número da conta: " << this->accountNumber << std::endl;
    std::cout << "Proprietário: " << this->owner->getName() << std::endl;
    this->printLast30Transactions();
    std::cout << "Saldo: R$" << this->balance << std::endl;
}
