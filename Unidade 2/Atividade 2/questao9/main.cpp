#include <iostream>
#include "Agenda.h"

using namespace std;

int main() {
    Agenda foo;
    Pessoa fulano("Lohan", 19, 1.72);

    foo.armazenaPessoa(fulano);
    foo.armazenaPessoa("Rosagenla", 53, 1.60);
    foo.armazenaPessoa("Linduardo", 47, 1.68);

    foo.imprimePovo();

    foo.removePessoa("Lohan");
    foo.imprimePovo();

    foo.removePessoa("Lohan");

    cout << foo.buscaPessoa("Lohan") << endl;
    cout << foo.buscaPessoa("Rosagenla") << endl;

    foo.imprimePessoa(1);
    foo.imprimePessoa(2);

    return 0;
}
