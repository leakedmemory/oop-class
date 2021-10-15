#include "Menu/Menu.hpp"

int main() {
    Bank bank("Banco",  12345678000190);
    Menu m(&bank);
    m.open();

    return 0;
}
