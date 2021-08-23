#include <iostream>
#include "Array.h"

using namespace std;

int main() {
    Array a1(4);
    Array a2(3);

    cin >> a1;
    cin >> a2;

    Array a3 = a1 + a2;

    cout << a3;

    a3 += a1;

    cout << a3;

    return 0;
}
