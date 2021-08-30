#ifndef Company_h
#define Company_h

#include "LegalPerson.h"
#include "Client.h"
#include "Employee.h"

class Company: public LegalPerson
{
public:
    Company(string, unsigned long, string);

    void hireEmployee(Employee &);
    void addClient(Client &);

    void listEmployees() const;
    void listClients() const;

    double payroll() const;

private:
    Employee employees[5];
    Client clients[5];
};

#endif
