#ifndef Account_hpp
#define Account_hpp

#include <iostream>

#include "../Persons/Person.hpp"

class Account
{
    friend std::ostream &operator<<(std::ostream &, const double);
    friend std::istream &operator>>(std::istream &, const double);

public:
    Account(unsigned, Person &);
    virtual ~Account();

    virtual void statement() const = 0;
    virtual void payment(double, const std::string &);

protected:
    unsigned accountNumber;
    Person *owner;
    double balance = 0;

private:
    std::string getDate() const;
    void cardPayment(double);
    void debitPayment(double);
};

#endif
