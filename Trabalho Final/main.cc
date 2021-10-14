#include <iostream>

#include "Persons/PhysicalPerson.hpp"
#include "Persons/LegalPerson.hpp"
#include "BankAccounts/SavingsAccount.hpp"
#include "BankAccounts/RegularCheckingAccount.hpp"
#include "BankAccounts/CheckingAccountWithLimit.hpp"

using namespace std;

int main() {
    PhysicalPerson lohan("Lohan", 123);
    LegalPerson ricardo("Ricardo", 456);
    PhysicalPerson julia("Júlia", 789);

    SavingsAccount n(123, &lohan, 500);
    cout << n.getOwnersName() << endl;
    cout << n.getBalance() << endl;

    RegularCheckingAccount a(456, &lohan, 300);
    cout << a.getOwnersName() << endl;
    cout << a.getBalance() << endl;

    CheckingAccountWithLimit h(789, &julia);
    cout << h.getOwnersName() << endl;
    cout << h.getBalance() << endl << endl;

    h >> 300;
    cout << h.getBalance() << endl << h.getLimit() << endl;
    h >> .01;
    h << 150;
    cout << h.getBalance() << endl;
    h << 200;
    cout << h.getBalance() << endl;
    h.transfer(n, 150);
    cout << h.getBalance() << endl << n.getBalance() << endl;

    return 0;
}
