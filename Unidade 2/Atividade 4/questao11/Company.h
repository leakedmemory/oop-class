#ifndef Company_h
#define Company_h

#include "LegalPerson.h"
#include "Client.h"
#include "Employee.h"

class Company: public LegalPerson
{
friend ostream &operator<<(ostream &, const Company &);

public:
    Company(string, unsigned long, string);

    void hireEmployee(const Employee &);
    void addClient(const Client &);

    void listEmployees() const;
    void listClients() const;

    double payroll() const;

private:
    Employee employees[5];
    unsigned employeesCounter = 0;

    Client clients[5];
    unsigned clientsCounter = 0;
};

#endif
