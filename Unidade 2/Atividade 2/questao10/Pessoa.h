#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa {
    public:
        Pessoa(string, int, float);
        Pessoa();

        inline string getNome() const { return nome; }

        inline int getIdade() const { return idade; }
        inline void setIdade(int idade) { this->idade = idade; }

        inline float getAltura() const { return altura; }
        inline void setAltura(float altura) { this->altura = altura; }

        void print() const;
        
    private:
        const string nome;
        int idade;
        float altura;
};

#endif
