#include "PhysicalPerson.h"
#include "LegalPerson.h"

int main() {
    PhysicalPerson physicalPerson("Lohan", 12345678900);
    LegalPerson legalPerson(
        "Petróleo Brasileiro S.A", 1234567891234500, "Petrobrás"
    );

    cout << physicalPerson;
    cout << legalPerson;
    cout << endl;

    physicalPerson.setName("João");
    physicalPerson.setCPF(98765432100);
    cout << "Nome: " << physicalPerson.getName() << "\nCPF: " <<
        physicalPerson.getCPF() << endl;
    cout << endl;

    legalPerson.setName("Contabilizei");
    legalPerson.setCNPJ(9876598765432100);
    legalPerson.setSocialReason("Contabilizei Contabilidade LTDA");
    cout << "Nome Fantasia: " << legalPerson.getName() << "\nRazão Social: "
        << legalPerson.getSocialReason() << "\nCNPJ: " <<
        legalPerson.getCNPJ() << endl;

    return 0;
}
