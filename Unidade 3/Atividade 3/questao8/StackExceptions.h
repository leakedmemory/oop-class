#ifndef StackExceptions_h
#define StackExceptions_h

#include <stdexcept>

using std::out_of_range;
using std::string;

class EmptyStackException: public out_of_range
{
public:
    EmptyStackException(const string& e="ERRO: impossível retirar item, pilha vazia.")
    : out_of_range(e) {}
};

class FullStackException: public out_of_range
{
public:
    FullStackException(const string& e="ERRO: impossível adicionar item, pilha cheia.")
    : out_of_range(e) {}
};

#endif
