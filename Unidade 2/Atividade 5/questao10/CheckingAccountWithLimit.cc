#include <iostream>
#include <sstream>

#include "CheckingAccountWithLimit.h"

void CheckingAccountWithLimit::withdraw(double value) {
    if (balance + limit >= value) {
        string date = getDate();

        ostringstream tmp;
        tmp << date << "  --  " << value << "  --  " << "Retirada de R$" <<
            value;
        string transition = tmp.str();

        this->balance -= value;
        addTransition(transition);
        this->transitionsQuantity++;

        if (balance < 0) {
            limit -= value;
        }

        cout << "Retirada de R$" << value << " efetuado." << endl;
    } else {
        cout << "Impossível fazer a retirada" << endl;
    }
}

void CheckingAccountWithLimit::deposit(double value) {
    string date = getDate();

    ostringstream tmp;
    tmp << date << "  --  " << value << "  --  " << "Depósito de R$" <<
        value;
    string transition = tmp.str();

    if (this->balance >= 0) {
        this->balance += value;
    } else {
        if (this->limit + value > FIXED_LIMIT) {
            this->limit = FIXED_LIMIT;
            this->balance = this->limit - value;
        } else if (this->limit + value < FIXED_LIMIT) {
            this->limit += value;
        } else {
            this->limit = FIXED_LIMIT;
            this->balance = 0;
        }
    }
    addTransition(transition);
    this->transitionsQuantity++;

    cout << "Depósito de R$" << value << " efetuado." << endl;
}

void CheckingAccountWithLimit::statement() const {
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
    cout << "Limite atual: " << this->limit << endl;
}
