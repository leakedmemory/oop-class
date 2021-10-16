#ifndef Menu_hpp
#define Menu_hpp

#include "../Bank/Bank.hpp"
#include "../Persons/Person.hpp"
#include "../Persons/PhysicalPerson.hpp"
#include "../Persons/LegalPerson.hpp"
#include "../BankAccounts/SavingsAccount.hpp"
#include "../BankAccounts/RegularCheckingAccount.hpp"
#include "../BankAccounts/CheckingAccountWithLimit.hpp"

class Menu
{
public:
    Menu(Bank*);

    void open();

private:
    Bank* bank;
    short int chooseFirstOperation() const;

    void managerLoop();
    short int chooseManagerOperation() const;
    void createAccount();
    short int askAccountType();
    Account* accountFactory(short int);
    short int askPersonType();
    Person* personFactory(short int);
    std::string askHolderName();
    unsigned long askCPF();
    unsigned long askCNPJ();
    PhysicalPerson* physicalPersonFactory(std::string, unsigned long);
    LegalPerson* legalPersonFactory(std::string, unsigned long);
    unsigned askAccountNumber();
    SavingsAccount* savingsAccountFactory(unsigned, Person*);
    RegularCheckingAccount* regularCheckingAccountFactory(unsigned, Person*);
    CheckingAccountWithLimit* checkingAccountWithLimitFactory(unsigned, Person*, double);
    double askLimit();
    void queryAccount(unsigned);
    void updateAccount(unsigned);
    short int askChange();
    void changeHandler(short int, Account*);
    unsigned askNewNumber();
    std::string askNewName();
    void deleteAccount(unsigned);

    void holderMenu();
    void holderLoop(Account*);
    short int chooseHolderOperation() const;
    void operationHolder(short int, Account*);
    void deposit(Account*);
    void withdraw(Account*);
    void seeStatement(Account*);
    void transfer(Account*, unsigned);

    void errorMessage() const;
    void cantFindAccount() const;
};

#endif
