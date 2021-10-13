#ifndef Account_hpp
#define Account_hpp

#include <iostream>

#include "../Persons/Person.hpp"

class Account
{
    friend void operator<<(Account&, double);
    friend std::istream& operator>>(std::istream&, double);

public:
    Account(unsigned, Person*, double=0);
    virtual ~Account();

    // virtual void seeStatement() const = 0;
    void makePayment(double, const std::string&);
    void transfer(Account&, double);

    unsigned getAccountNumber() const;
    std::string getOwnersName() const;
    double getBalance() const;

protected:
    unsigned accountNumber;
    Person* owner;
    double balance;

    virtual void debitPayment(double);
    virtual void transferMoney(Account&, double);
    virtual void canTransfer(double);

private:
    std::string getDate() const;
    void logError(std::exception& e);
    void cardPayment(double);
    void paymentWithCardOrDebit(double, const std::string&);
    void makePaymentWithCardOrDebit(double, const std::string&);
};

#endif
