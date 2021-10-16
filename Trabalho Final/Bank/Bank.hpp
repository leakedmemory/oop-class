#ifndef Bank_hpp
#define Bank_hpp

#include <vector>

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
    bool searchAccount(unsigned);
    Account* getAccountByNumber(unsigned);
    std::vector<Person*>* getHolders();
    std::vector<Account*>* getAccounts();

    void addAccount(Account*);

private:
    std::vector<Person*> holders;
    std::vector<Account*> accounts;

    void addHolder(Person*);
};

#endif
