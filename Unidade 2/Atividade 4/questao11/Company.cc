#include "Company.h"

ostream &operator<<(ostream &out, const Company &company) {
    out << "Nome: " << company.getName();
    out << "\nCNPJ: " << company.getCNPJ();
    out << "\nRazão Social: " << company.getSocialReason();

    out << "\n\nFuncionários:\n";
    for (int index = 0; index < company.employeesCounter; index++) {
        out << company.employees[index] << endl;
    }

    out << "Clientes:\n";
    for (int index = 0; index < company.clientsCounter; index++) {
        out << company.clients[index] << endl;
    }

    return out;
}

Company::Company(
    string name, unsigned long CNPJ, string socialReason
) : LegalPerson(name, CNPJ, socialReason) {}

void Company::hireEmployee(const Employee &employee) {
    employees[employeesCounter] = employee;
    employeesCounter++;
}

void Company::addClient(const Client &client) {
    clients[clientsCounter] = client;
    clientsCounter++;
}

void Company::listEmployees() const {
    for (int index = 0; index < employeesCounter; index++) {
        cout << employees[index].getName() << endl;
    }
}

void Company::listClients() const {
    for (int index = 0; index < clientsCounter; index++) {
        cout << clients[index].getName() << endl;
    }
}

double Company::payroll() const {
    double payroll = 0;

    for (int index = 0; index < employeesCounter; index++) {
        payroll += employees[index].grossSalary();
    }

    return payroll;
}
