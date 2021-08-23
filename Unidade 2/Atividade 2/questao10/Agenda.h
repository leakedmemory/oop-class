#ifndef AGENDA_H
#define AGENDA_H

#include "Pessoa.h"

class Agenda {
    public:
        Agenda(int=1);
        ~Agenda();

        void armazenaPessoa(string, int, float);
        void armazenaPessoa(Pessoa &);

        void removePessoa(string);

        int buscaPessoa(string) const;
        void imprimePovo() const;
        void imprimePessoa(int i) const;

        inline int quantidadeAgendamentos() const { return agendamentos; }
    private:
        Pessoa *pessoas;
        int agendamentos;
        int quantidadePessoas;
};

#endif
