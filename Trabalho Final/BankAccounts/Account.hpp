#ifndef Account_hpp
#define Account_hpp

#include <vector>

#include "../Persons/Person.hpp"

class Account
{
    friend void operator<<(Account&, double);
    friend void operator>>(Account&, double);

public:
    Account(unsigned, Person*, double=0);
    virtual ~Account();

    virtual void seeStatement() const = 0;
    void makePayment(double, const std::string&);
    void transfer(Account&, double);

    void setAccountNumber(unsigned);
    void setOwnersName(std::string);
    unsigned getAccountNumber() const;
    std::string getOwnersName() const;
    std::string getBalance() const;
    Person* getOwner() const;

protected:
    unsigned accountNumber;
    Person* owner;
    double balance;
    std::vector<std::string> transactions;

    virtual void withdraw(double);
    void logError(std::exception& e) const;
    void addTransaction(double, const std::string&);
    unsigned short getTransactionsSize() const;
    void printLast30Transactions() const;

private:
    std::string getActualDate() const;
    void cardPayment(double);
    void debitPayment(double);
    void paymentWithCardOrDebit(double, const std::string&);
    void transferMoney(Account&, double);
};

#endif
