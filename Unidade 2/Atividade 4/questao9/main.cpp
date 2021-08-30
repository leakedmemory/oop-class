#include "Employee.h"

int main() {
    Employee employee("Lohan", 12345678900, "202011250010", 5000, 160, 180);

    cout << employee;

    cout << endl;
    
    cout << "Salário bruto: R$" << employee.grossSalary() << endl;

    cout << endl;

    employee.setName("José");
    employee.setCPF(98765432100);
    employee.setRegistration("010052110202");
    employee.setSalary(7500);
    employee.setMonthlyHours(140);
    employee.setMonthlyWorkedHours(160);

    cout << employee.getName() << endl;
    cout << employee.getCPF() << endl;
    cout << employee.getRegistration() << endl;
    cout << employee.getSalary() << endl;
    cout << employee.getMonthlyHours() << endl;
    cout << employee.getMonthlyWorkedHours() << endl;

    return 0;
}
