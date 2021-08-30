#include <iostream>
#include "NewProperty.h"
#include "OldProperty.h"

int main() {
    NewProperty newHouse;
    OldProperty oldHouse("Rua da casa velha", 25000, 0.1);

    newHouse.setAddress("Rua da casa nova");
    newHouse.setValue(104898.35);
    newHouse.setAddition(0.26);

    cout << oldHouse.getAddress() << endl;
    cout << oldHouse.getValue() << endl;
    cout << oldHouse.getDecrease() << endl;

    cout << endl;

    cout << newHouse.getAddress() << endl;
    cout << newHouse.getValue() << endl;
    cout << newHouse.getAddition() << endl;

    return 0;
}
