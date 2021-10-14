#ifndef Account_hpp
#define Account_hpp

#include "../Persons/Person.hpp"

class Account
{
    friend void operator<<(Account&, double);
    friend void operator>>(Account&, double);

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
    virtual void withdraw(double);
    void logError(std::exception& e) const;

private:
    std::string getActualDate() const;
    void cardPayment(double) const;
    void paymentWithCardOrDebit(double, const std::string&);
    void transferMoney(Account&, double);
};

#endif
