#include "Client.h"

int main() {
    Client client("Lohan", 12345678900, 83991778565, "Rua Onde Moro");

    cout << client;

    cout << endl;

    client.setPhoneNumber(11991778565);
    client.setAddress("Rua Moisés Lopes de Lira");
    
    cout << client.getPhoneNumber() << endl;
    cout << client.getAddress() << endl;

    return 0;
}
