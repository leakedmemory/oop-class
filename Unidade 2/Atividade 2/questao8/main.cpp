#include <iostream>
#include "Pessoa.h"

using namespace std;

int main() {
    Pessoa fulano("Lohan Yrvine", 19, 1.72);

    fulano.print();

    fulano.setAltura(1.80);
    cout << "\n" << fulano.getAltura() << "m" << endl;

    fulano.setIdade(20);
    cout << "\n" << fulano.getIdade() << " anos\n" << endl;

    fulano.print();

    return 0;
}
