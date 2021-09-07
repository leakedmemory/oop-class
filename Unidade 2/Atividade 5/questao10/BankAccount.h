#ifndef BankAccount_h
#define BankAccount_h

#include <string>

using namespace std;

class BankAccount
{
public:
    BankAccount(unsigned, string);
    virtual ~BankAccount() {}

    virtual void deposit(double);
    virtual void withdraw(double);
    virtual void statement() const = 0;

    void payment(double, string);

protected:
    unsigned accountNumber;
    string name;
    double balance = 0;

    string transitions[11];
    unsigned transitionsQuantity = 0;

    string getDate() const;
    void addTransition(string);
};

#endif
