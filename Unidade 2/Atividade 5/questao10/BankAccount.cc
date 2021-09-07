#include <iostream>
#include <ctime>
#include <sstream>

#include "BankAccount.h"

BankAccount::BankAccount(unsigned accountNumber, string name) {
    this->accountNumber = accountNumber;
    this->name = name;
}

string BankAccount::getDate() const {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    unsigned day = ltm->tm_mday;
    unsigned month = 1 + ltm->tm_mon;
    unsigned year = 1900 + ltm->tm_year;

    ostringstream oss;
    oss << day << " " << month << " " << year;
    return oss.str();
}

void BankAccount::addTransition(string transition) {
    if (transitionsQuantity < 10) {
        this->transitions[this->transitionsQuantity] = transition;
    } else {
        for (int index = 0; index < 9; index++) {
            this->transitions[index] = this->transitions[index+1];
        }

        this->transitions[9] = transition;
    }
}

void BankAccount::deposit(double value) {
    string date = getDate();

    ostringstream tmp;
    tmp << date << "  --  " << value << "  --  " << "Depósito de R$" <<
        value;
    string transition = tmp.str();

    this->balance += value;
    addTransition(transition);
    this->transitionsQuantity++;

    cout << "Depósito de R$" << value << " efetuado." << endl;
}

void BankAccount::withdraw(double value) {
    if (this->balance - value >= 0) {
        string date = getDate();

        ostringstream tmp;
        tmp << date << "  --  " << value << "  --  " << "Retirada de R$" <<
            value;
        string transition = tmp.str();

        this->balance -= value;
        addTransition(transition);
        this->transitionsQuantity++;

        cout << "Retirada de R$" << value << " efetuado." << endl;
    } else {
        cout << "Impossível fazer a retirada." << endl;
    }
}

void BankAccount::payment(double value, string type) {
    if (type == "debito" || type == "credito") {
        if (type == "debito") {
            if (this->balance - value >= 0) {
                this->balance -= value;

                string date = getDate();

                ostringstream tmp;
                tmp << date << "  --  -R$" << value << "  --  " <<
                    "Pagamento em débito efetuado ";
                string transition = tmp.str();

                addTransition(transition);
                this->transitionsQuantity++;

                cout << "Pagamento em débito efetuado." << endl;
            } else {
                cout << "ERRO: pagamento não autorizado." << endl;
            }
        } else {
            string date = getDate();

            ostringstream tmp;
            tmp << date << "  --  R$" << value << "  --  " <<
                "Pagamento em crédito efetuado ";
            string transition = tmp.str();

            addTransition(transition);
            this->transitionsQuantity++;

            cout << "Pagamento em crédito efetuado." << endl;
        }
    } else {
        cout << "ERRO: pagamento não autorizado." << endl;
    }
}
