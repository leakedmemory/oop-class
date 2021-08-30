#include "Employee.h"

ostream &operator<<(ostream &out, const Employee &employee) {
    out << "Nome: " << employee.getName();
    out << "\nCPF: " << employee.getCPF();
    out << "\nMatrícula: " << employee.getRegistration();
    out << "\nSalário: " << employee.getSalary();
    out << "\nHoras mensais: " << employee.getMonthlyHours();
    out << "\nHoras trabalhadas: " << employee.getMonthlyWorkedHours();
    out << endl;

    return out;
}

Employee::Employee(
    string name, unsigned long CPF, string registration,
    double salary, int monthlyHours, int monthlyWorkedHours
) : PhysicalPerson(name, CPF), registration(registration), salary(salary),
    monthlyHours(monthlyHours), monthlyWorkedHours(monthlyWorkedHours) {}

double Employee::grossSalary() const {
    return (salary * monthlyWorkedHours/monthlyHours);
}
