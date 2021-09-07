#include <iostream>

#include "SavingsAccount.h"

void SavingsAccount::statement() const {
    cout << "Número da conta: " << this->accountNumber << endl;
    cout << "Nome: " << this->name << endl;

    int tmp;
    if (this->transitionsQuantity < 10) {
        tmp = this->transitionsQuantity;
    }
    else {
        tmp = 10;
    }
    for (int index = 0; index < tmp; index++) {
        cout << this->transitions[index] << endl;
    }


    cout << "Saldo: " << this->balance << endl;
    cout << "Aniversário da conta: " << this->anniversaryDay << endl;
}
