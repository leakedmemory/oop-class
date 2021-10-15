#include <iostream>

#include "Persons/PhysicalPerson.hpp"
#include "Persons/LegalPerson.hpp"
#include "BankAccounts/SavingsAccount.hpp"
#include "BankAccounts/RegularCheckingAccount.hpp"
#include "BankAccounts/CheckingAccountWithLimit.hpp"
#include "Bank/Bank.hpp"

using namespace std;

int main() {
    PhysicalPerson lohan("Lohan", 123);
    LegalPerson ricardo("Ricardo", 456);
    PhysicalPerson julia("Júlia", 789);

    SavingsAccount n(123, &lohan, 500);
    RegularCheckingAccount a(456, &lohan, 300);
    CheckingAccountWithLimit h(789, &julia, 500, -1);

    n << 200;
    n >> 100;
    n.transfer(h, 50);
    n.seeStatement();
    cout << endl;

    h >> 700;
    h << 370;
    h.transfer(a, 64);
    h.seeStatement();
    cout << endl;

    a.makePayment(40, "debito");
    a.makePayment(30, "credito");
    a << 20;
    a.seeStatement();

    return 0;
}
