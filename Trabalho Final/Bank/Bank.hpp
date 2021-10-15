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

    void listHoldersAccounts(const Person&) const;
    void listRegisteredAccounts() const;

    void addAccount(Account*);
    void addHolder(Person*);

private:
    std::vector<Person*> holders;
    std::vector<Account*> accounts;
};

#endif
