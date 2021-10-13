#ifndef InsufficientFundsError_hpp
#define InsufficientFundsError_hpp

#include <stdexcept>

class InsufficientFundsError: public std::underflow_error
{
public:
    InsufficientFundsError(const std::string& e="ERRO: saldo insuficiente.") :
        std::underflow_error(e) {}
};

#endif
