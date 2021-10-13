#ifndef LimitExceededError_hpp
#define LimitExceededError_hpp

#include "InsufficientFundsError.hpp"

class LimitExceededError: public InsufficientFundsError
{
public:
    LimitExceededError(const std::string& e="ERRO: limite insuficiente.") :
        InsufficientFundsError(e) {}
};

#endif
