#include "Bank.hpp"

Bank::Bank(std::string name, unsigned long cnpj) : PhysicalPerson(name, cnpj) {
    // Load archives
}

Bank::~Bank() {
    // Save archives
}

void Bank::listHoldersAccounts(Account& account) const {

}

void Bank::listRegisteredAccounts() const {

}
