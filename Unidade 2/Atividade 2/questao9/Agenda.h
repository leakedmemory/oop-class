#ifndef AGENDA_H
#define AGENDA_H

#include "Pessoa.h"

class Agenda {
    public:
        Agenda() { agendamentos = 0; }

        void armazenaPessoa(string, int, float);
        void armazenaPessoa(Pessoa &);

        void removePessoa(string);

        int buscaPessoa(string) const;
        void imprimePovo() const;
        void imprimePessoa(int i) const;

        inline int quantidadeAgendamentos() const { return agendamentos; }
    private:
        Pessoa *pessoas[10];
        int agendamentos;
};

#endif
