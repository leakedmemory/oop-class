#ifndef InvalidPaymentMethodError_hpp
#define InvalidPaymentMethodError_hpp

#include <stdexcept>

class InvalidPaymentMethodError: public std::invalid_argument
{
public:
    InvalidPaymentMethodError(const std::string e="ERRO: método de pagamento inválido.") :
        std::invalid_argument(e) {}
};

#endif
