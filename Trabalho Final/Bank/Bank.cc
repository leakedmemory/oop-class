#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "Bank.hpp"
#include "../Persons/LegalPerson.hpp"
#include "../BankAccounts/SavingsAccount.hpp"
#include "../BankAccounts/RegularCheckingAccount.hpp"
#include "../BankAccounts/CheckingAccountWithLimit.hpp"

Bank::Bank(std::string name, unsigned long cnpj): PhysicalPerson(name, cnpj) {
    // Load archives
}

Bank::~Bank() {
    std::ofstream data_base("data/data_base.txt", std::ios::out);

    for (unsigned i = 0; i < holders.size(); i++) {
        std::ostringstream line;
        PhysicalPerson* holder = dynamic_cast<PhysicalPerson*>(holders[i]);
        if (holder) {
            line << "PH-" << holder->getName() << "-" << holder->getCPF() << std::endl;
            data_base << line.str();
        } else {
            LegalPerson* holder = dynamic_cast<LegalPerson*>(holders[i]);
            line << "LH-" << holder->getName() << "-" << holder->getCNPJ() << std::endl;
            data_base << line.str();
        }
    }

    for (unsigned i = 0; i < accounts.size(); i++) {
        std::ostringstream line;
        SavingsAccount* account = dynamic_cast<SavingsAccount*>(accounts[i]);
        if (account) {
            line << "SA-" << account->getAccountNumber() << "-" <<
                account->getOwnersName() << "-" << account->getBalance() << std::endl;
            data_base << line.str();

            std::vector<std::string>* transactions = account->getTransactions();
            for (unsigned long j = 0; j < transactions->size(); j++) {
                std::ostringstream another_line;
                another_line << "T-" << (*transactions)[j] << std::endl;
                data_base << another_line.str();
            }
        } else {
            RegularCheckingAccount* account = dynamic_cast<
                RegularCheckingAccount*
            >(accounts[i]);
            if (account) {
                line << "RCA-" << account->getAccountNumber() << "-" <<
                    account->getOwnersName() << "-" << account->getBalance() << std::endl;
                data_base << line.str();

                std::vector<std::string>* transactions = account->getTransactions();
                for (unsigned long j = 0; j < transactions->size(); j++) {
                    std::ostringstream another_line;
                    another_line << "T-" << (*transactions)[j] << std::endl;
                    data_base << another_line.str();
                }
            } else {
                CheckingAccountWithLimit* account = dynamic_cast<
                    CheckingAccountWithLimit*
                >(accounts[i]);
                line << "CLA-" << account->getAccountNumber() << "-" <<
                    account->getOwnersName() << "-" << account->getLimit() <<
                    "-" << account->getBalance() << std::endl;
                data_base << line.str();
                std::vector<std::string>* transactions = account->getTransactions();
                for (unsigned long j = 0; j < transactions->size(); j++) {
                    std::ostringstream another_line;
                    std::cout << (*transactions)[j] << std::endl;
                    another_line << "T-" << (*transactions)[j] << std::endl;
                    data_base << another_line.str();
                }
            }
        }
    }

    data_base.close();
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

bool Bank::searchAccount(unsigned number) {
    for (unsigned i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == number) {
            return true;
        }
    }

    return false;
}

Account* Bank::getAccountByNumber(unsigned number) {
    for (unsigned i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == number) {
            return accounts[i];
        }
    }

    return nullptr;
}

std::vector<Person*>* Bank::getHolders() {
    return &this->holders;
}

std::vector<Account*>* Bank::getAccounts() {
    return &this->accounts;
}
