#include <iostream>

#include "BankAccount.h"
#include "RegularCheckingAccount.h"
#include "CheckingAccountWithLimit.h"
#include "SavingsAccount.h"

int main() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    unsigned day = ltm->tm_mday;

    BankAccount *accounts[] = {
        new RegCheckingAccount(1, "João"),
        new CheckingAccountWithLimit(2, "José", 50),
        new SavingsAccount(3, "Maria", day)
    };

    accounts[0]->deposit(50);
    accounts[0]->withdraw(30);
    accounts[0]->withdraw(30);
    accounts[0]->payment(25, "debito");
    accounts[0]->payment(10, "debito");
    accounts[0]->payment(40, "credito");
    cout << endl;
    accounts[0]->statement();
    
    cout << endl;

    accounts[1]->deposit(50);
    accounts[1]->withdraw(30);
    accounts[1]->withdraw(30);
    accounts[1]->payment(25, "debito");
    accounts[1]->payment(10, "debito");
    accounts[1]->payment(40, "credito");
    accounts[1]->withdraw(70);
    cout << endl;
    accounts[1]->statement();

    cout << endl;

    accounts[2]->deposit(50);
    accounts[2]->withdraw(30);
    accounts[2]->withdraw(30);
    accounts[2]->payment(25, "debito");
    accounts[2]->payment(10, "debito");
    accounts[2]->payment(40, "credito");
    cout << endl;
    accounts[2]->statement();

    for (int index = 0; index < 3; index ++) {
        delete accounts[index];
    }

    return 0;
}
