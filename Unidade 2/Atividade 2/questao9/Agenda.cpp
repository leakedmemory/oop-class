#include <iostream>
#include "Agenda.h"

using namespace std;

void Agenda::armazenaPessoa(string nome, int idade, float altura) {
    (pessoas[agendamentos]) = new Pessoa(nome, idade, altura);
    agendamentos++;
}

void Agenda::armazenaPessoa(Pessoa &pessoa) {
    pessoas[agendamentos] = &(pessoa);
    agendamentos++;
}

void Agenda::removePessoa(string nome) {
    bool flag = false;

    for (int i = 0; i < agendamentos; i++) {
        if (pessoas[i]->getNome() == nome) {
            if (agendamentos == 1) {
                pessoas[i] = nullptr;
            } else {
                int j = i;

                for (int k = j+1; k < agendamentos; k++) {
                    pessoas[j] = pessoas[k];
                    j++;

                    if (j == agendamentos) {
                        pessoas[j] = nullptr;
                    }
                }
            }
            
            flag = true;
            agendamentos--;
            break;
        }
    }

    if (!flag) {
        cout << "Nenhuma pessoa com o nome " << nome << " está agendada." 
        << endl;
    }
    
}

int Agenda::buscaPessoa(string nome) const {
    if (agendamentos) {
        bool flag = false;

        for (int index = 0; index < agendamentos; index++) {
            if (pessoas[index]->getNome() == nome) {
                return index+1;
            }
        }

        if (!flag) {
            return -1;
        }
    } else {
        return -1;
    }
}

void Agenda::imprimePessoa(int i) const {
    if (i > agendamentos) {
        cout << "Não há ninguém com esse número." << endl;
    } else {
        pessoas[i-1]->print();
    }
}

void Agenda::imprimePovo() const {
    if (agendamentos) {
        for (int index = 0; index < agendamentos; index++) {
            cout << pessoas[index]->getNome() << endl;
        }
    } else {
        cout << "Não há nenhum agendamento." << endl;
    }
}
