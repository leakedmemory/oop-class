#include <iostream>

#include "Persons/PhysicalPerson.hpp"
#include "Persons/LegalPerson.hpp"
#include "BankAccounts/SavingsAccount.hpp"
#include "BankAccounts/RegularCheckingAccount.hpp"
#include "BankAccounts/CheckingAccountWithLimit.hpp"
#include "Bank/Bank.hpp"

using std::cout;
using std::endl;

int main() {
    PhysicalPerson lohan("Lohan", 123);
    LegalPerson ricardo("Ricardo", 456);
    PhysicalPerson julia("Júlia", 789);

    SavingsAccount n(123, &lohan, 500);
    RegularCheckingAccount a(456, &lohan, 300);
    CheckingAccountWithLimit h(789, &julia, 500, -1);

    Bank bb("bb", 135);
    bb.addAccount(&n);
    bb.addAccount(&a);
    bb.listRegisteredAccounts();
    bb.listHoldersAccounts(lohan);

    return 0;
}
