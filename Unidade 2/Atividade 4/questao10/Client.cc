#include "Client.h"

ostream &operator<<(ostream &out, const Client &client) {
    out << "Nome: " << client.getName();
    out << "\nCPF: " << client.getCPF();
    out << "\nNúmero do telefone: " << client.getPhoneNumber();
    out << "\nEndereço: " << client.getAddress();
    out << endl;

    return out;
}

Client::Client(
    string name, unsigned long CPF, unsigned long phoneNumber,
        string address
) : PhysicalPerson(name, CPF), phoneNumber(phoneNumber),
    address(address) {}
