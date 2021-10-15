#include <iostream>

#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(
    unsigned accountNumber, Person* owner, double balance, unsigned short anniversaryDay
) : Account(accountNumber, owner, balance) {
    this->anniversaryDay = (
        (anniversaryDay >= 1 && anniversaryDay <= 31) ? anniversaryDay : 1
    );
}

SavingsAccount::~SavingsAccount() {}

void SavingsAccount::seeStatement() const {
    std::cout << "Número da conta: " << this->accountNumber << std::endl;
    std::cout << "Proprietário: " << this->owner->getName() << std::endl;
    std::cout << "Aniversário da conta: " << this->anniversaryDay << std::endl;
    this->printLast30Transactions();
    std::cout << "Saldo: R$" << this->balance << std::endl;
}
