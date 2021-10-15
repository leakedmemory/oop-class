#ifndef Bank_hpp
#define Bank_hpp

#include "vector"

#include "../Persons/Person.hpp"
#include "../Persons/PhysicalPerson.hpp"
#include "../BankAccounts/Account.hpp"

class Bank: public PhysicalPerson
{
public:
    Bank(std::string, unsigned long);
    ~Bank() final;

    void listHoldersAccounts(Account&) const;
    void listRegisteredAccounts() const;

private:
    std::vector<Person> holders;
    std::vector<Account> accounts;
};

#endif
