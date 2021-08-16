#include <iostream>
#include "Pessoa.h"

using namespace std;

Pessoa::Pessoa(string nome, int idade, float altura) : nome(nome) {
    this->setIdade(idade);
    this->setAltura(altura);
}

void Pessoa::print() const {
    cout << "Nome: " << this->nome << endl;
    cout << "Idade: " << this->idade << " anos" << endl;
    cout << "Altura: " << this->altura << "m" << endl;
}
