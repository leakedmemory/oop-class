#ifndef QueueExceptions_h
#define QueueExceptions_h

#include <stdexcept>

using std::out_of_range;
using std::string;

class EmptyQueueException: public out_of_range
{
public:
    EmptyQueueException(const string& e="ERRO: impossível remover item, fila vazia.")
    : out_of_range(e) {}
};

class FullQueueException: public out_of_range
{
public:
    FullQueueException(const string& e="ERRO: impossível adicionar item, fila cheia.")
    : out_of_range(e) {}
};

#endif
