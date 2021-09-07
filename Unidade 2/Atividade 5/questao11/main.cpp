#include <iostream>

#include "Agenda.h"

int main() {
    Agenda agenda;

    agenda.addPerson("fisica");
    cout << endl;
    agenda.addPerson("juridica");
    cout << endl;
    agenda.listContacts();
    cout << endl;

    agenda.removePerson("Lohan");
    agenda.listContacts();
    cout << endl;

    agenda.removePerson("Teste");
    cout << endl;

    agenda.addPerson("fisica");
    cout << endl;
    agenda.addPerson("fisica");
    cout << endl;
    agenda.addPerson("juridica");
    cout << endl;
    agenda.addPerson("fisica");
    cout << endl;
    agenda.addPerson("juridica");
    cout << endl;
    agenda.listContacts();
    cout << endl;

    string person;
    cout << "Quem deseja alterar? ";
    cin >> person;
    agenda.updatePerson(person);
    cout << endl;
    cout << "Quem deseja alterar? ";
    cin >> person;
    agenda.updatePerson(person);
    cout << endl;
    cout << "Quem deseja alterar? ";
    cin >> person;
    agenda.updatePerson(person);
    cout << endl;
    cout << "Quem deseja alterar? ";
    cin >> person;
    agenda.updatePerson(person);
    cout << endl;

    agenda.listContacts();

    return 0;
}
