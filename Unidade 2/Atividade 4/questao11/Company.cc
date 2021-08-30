#include "Company.h"

Company::Company(
    string name, unsigned long CNPJ, string socialReason
) : LegalPerson(name, CNPJ, socialReason) {}

void Company::hireEmployee(Employee &employee) {

}

void Company::addClient(Client &client) {

}

void Company::listEmployees() const {

}

void Company::listClients() const {

}

double Company::payroll() const {

}
