#include <iostream>
#include <algorithm>
#include <fstream>

#include "Bank.hpp"

Bank::Bank(std::string name, unsigned long cnpj) : PhysicalPerson(name, cnpj) {
    // Load archives
}

Bank::~Bank() {
    std::ofstream fout("data/bank_data.txt", std::ios::out);

    for (unsigned i = 0; i < holders.size(); i++) {
        fout << holders[i]->getName() << std::endl;
    }

    fout.close();
}

void Bank::listHoldersAccounts(const Person& person) const {
    std::cout << "Contas cadastradas em nome de " << person.getName() << ":" << std::endl;
    for (unsigned i = 0; i < this->accounts.size(); i++) {
        if (this->accounts[i]->getOwnersName() == person.getName()) {
            std::cout << this->accounts[i]->getAccountNumber() << std::endl;
        }
    }
}

void Bank::listRegisteredAccounts() const {
    for (unsigned i = 0; i < this->accounts.size(); i++) {
        std::cout << "Número da conta: " << this->accounts[i]->getAccountNumber() << std::endl;
        std::cout << "Proprietário: " << this->accounts[i]->getOwnersName() << std::endl;
        std::cout << "Saldo: " << this->accounts[i]->getBalance() << std::endl;
    }
}

void Bank::addAccount(Account* holder) {
    this->accounts.push_back(holder);
    this->addHolder(holder->getOwner());
}

void Bank::addHolder(Person* holder) {
    if(!(std::find(holders.begin(), holders.end(), holder) != holders.end())) {
        holders.push_back(holder);
    }
}
