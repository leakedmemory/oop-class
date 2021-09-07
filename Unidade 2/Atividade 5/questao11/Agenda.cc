#include <iostream>

#include "Agenda.h"
#include "LegalPerson.h"
#include "PhysicalPerson.h"

Agenda::~Agenda() {
    for (int index = 0; index < this->numberOfContacts; index++) {
        delete this->contacts[index];
    }
}

void Agenda::addPerson(string type) {
    if (this->numberOfContacts == 5) {
        cout << "Agenda cheia." << endl;
    } else if (type != "fisica" && type != "juridica") {
        cout << "ERRO: informar tipo de pessoa válido." << endl;
    } else {
        string name;
        string address;
        string email;

        cout << "Nome: ";
        cin >> name;
        cout << "Endereço: ";
        cin >> address;
        cout << "Email: ";
        cin >> email;

        if (type == "fisica") {
            unsigned long CPF;
            string dateOfBirth;
            string maritalStatus;

            cout << "CPF: ";
            cin >> CPF;
            cout << "Data de nascimento: ";
            cin >> dateOfBirth;
            cout << "Estado civil: ";
            cin >> maritalStatus;

            this->contacts[this->numberOfContacts] = new PhysicalPerson(
                name, address, email, CPF, dateOfBirth, maritalStatus
            );
        } else {
            unsigned long CNPJ;
            unsigned long stateRegistration;
            string socialReason;

            cout << "CNPJ: ";
            cin >> CNPJ;
            cout << "Registro estadual: ";
            cin >> stateRegistration;
            cout << "Razão social: ";
            cin >> socialReason;

            this->contacts[this->numberOfContacts] = new LegalPerson(
                name, address, email, CNPJ, stateRegistration, socialReason
            );
        }

        this->numberOfContacts++;
    }
}

void Agenda::addPerson(Person *person) {
    if (this->numberOfContacts == 5) {
        cout << "Agenda cheia." << endl;
    } else {
        this->contacts[this->numberOfContacts] = person;
        this->numberOfContacts++;
    }
}

void Agenda::removePerson(string name) {
    bool flag = false;
    for (int index = 0; index < this->numberOfContacts; index++) {
        if (name == this->contacts[index]->getName()) {
            flag = true;

            if (this->numberOfContacts == 1) {
                delete this->contacts[index];
            } else {
                int k = index;
                for (int j = index+1; j < this->numberOfContacts; j++) {
                    this->contacts[k] = this->contacts[j];
                    k++;

                    if (k == this->numberOfContacts) {
                        delete this->contacts[j];
                    }
                }
            }

            this->numberOfContacts--;
            break;
        }
    }

    if (!flag) {
        cout << "Pessoa com esse nome não encontrada." << endl;
    }
}

void Agenda::updatePerson(string name) {
    bool flag = false;
    for (int index = 0; index < this->numberOfContacts; index++) {
        if (name == this->contacts[index]->getName()) {
            flag = true;
            string alteration;

            cout << "O que deseja alterar? ";
            cin >> alteration;

            if (alteration == "nome") {
                string newName;
                cout << "Digite o novo nome: ";
                cin >> newName;
                this->contacts[index]->setName(newName);
            } else if (alteration == "endereco") {
                string newAddress;
                cout << "Digite o novo endereço: ";
                cin >> newAddress;
                this->contacts[index]->setAddress(newAddress);
            } else if (alteration == "email") {
                string newEmail;
                cout << "Digite o novo email: ";
                cin >> newEmail;
                this->contacts[index]->setEmail(newEmail);
            } else {
                cout << "Tipo de mudança inválida." << endl;
            }
        }
    }

    if (!flag) {
        cout << "Pessoa com essa não encontrada." << endl;
    }
}

void Agenda::listContacts() const {
    if (this->numberOfContacts == 0) {
        cout << "A agenda está vazia." << endl;
    } else {
        for (int index = 0; index < this->numberOfContacts; index++) {
            Person *contact = this->contacts[index];
            cout << contact->getName() << " - " << contact->getEmail() <<
                " - " << contact->getAddress() << endl;
        }
    }   
}
