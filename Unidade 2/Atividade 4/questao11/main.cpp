#include "Company.h"

int main() {
    Company company("Petróleo Brasileiro S.A", 1234567891234500, "Petrobrás");

    Employee employee("Lohan", 12345678900, "202011250010", 5000, 160, 160);

    company.hireEmployee(employee);
    company.hireEmployee(
        Employee("Roberta", 98765432100, "010052110202", 7500, 160, 180)
    );
    company.listEmployees();
    cout << endl;

    Client client("José", 12345987600, 40028922, "Rua Onde Mora");

    company.addClient(client);
    company.addClient(
        Client("Marcos", 98761234500, 84587719983, "Rua Onde Mora")
    );
    company.listClients();
    cout << endl;

    cout << "Folha de pagamento: R$" << company.payroll() << endl;
    cout << endl;

    cout << company;

    return 0;
}
