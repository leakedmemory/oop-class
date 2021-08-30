#include "PhysicalPerson.h"
#include "LegalPerson.h"

int main() {
    PhysicalPerson pessoaFisica("Lohan", 12345678900);
    LegalPerson pessoaJuridica(
        "Petrobrás", 1234567891234500, "Petróleo Brasileiro S.A"
    );

    cout << pessoaFisica;
    cout << pessoaJuridica;
    cout << endl;

    pessoaFisica.setName("João");
    pessoaFisica.setCPF(98765432100);
    cout << "Nome: " << pessoaFisica.getName() << "\nCPF: " <<
        pessoaFisica.getCPF() << endl;
    cout << endl;

    pessoaJuridica.setName("Contabilizei");
    pessoaJuridica.setCNPJ(9876598765432100);
    pessoaJuridica.setSocialReason("Contabilizei Contabilidade LTDA");
    cout << "Nome Fantasia: " << pessoaJuridica.getName() << "\nRazão Social: "
        << pessoaJuridica.getSocialReason() << "\nCNPJ: " <<
        pessoaJuridica.getCNPJ() << endl;

    return 0;
}
