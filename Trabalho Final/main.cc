#include <iostream>

#include "Persons/PhysicalPerson.hpp"
#include "Persons/LegalPerson.hpp"
#include "BankAccounts/SavingsAccount.hpp"
#include "BankAccounts/RegularCheckingAccount.hpp"

using namespace std;

int main() {
    PhysicalPerson lohan("Lohan Yrvine", 11063810418);
    SavingsAccount n(123, &lohan, 500);
    cout << n.getOwnersName() << endl;
    cout << n.getBalance() << endl;

    LegalPerson batata("batata", 321);
    SavingsAccount m(321, &batata);
    cout << m.getOwnersName() << endl;
    cout << m.getBalance() << endl << endl;

    RegularCheckingAccount a(456, &lohan, 300);
    cout << a.getOwnersName() << endl;
    cout << a.getBalance() << endl;

    RegularCheckingAccount b(654, &batata);
    cout << b.getOwnersName() << endl;
    cout << b.getBalance() << endl << endl;

    n.transfer(m, 300);
    cout << n.getBalance() << endl;
    cout << m.getBalance() << endl << endl;

    a.transfer(b, 64.92);
    cout << a.getBalance() << endl;
    cout << b.getBalance() << endl << endl;

    b.transfer(n, .91);
    cout << b.getBalance() << endl;
    cout << n.getBalance() << endl << endl;

    n.transfer(a, 300);
    b.makePayment(90, "batata");
    m.makePayment(300, "debito");
    m.makePayment(0.01, "debito");

    return 0;
}
