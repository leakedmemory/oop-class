#include <iostream>
#include <string>
#include "Array.h"

int main() {
    Array<int> i1(5);
    cin >> i1;
    cout << i1 << endl;

    Array<int> i2(5);
    cin >> i2;
    cout << i2 << endl;

    cout << "i1 == i2: " << (i1 == i2) << endl << endl;

    Array<string> s1(3);
    cin >> s1;
    cout << s1 << endl;

    Array<string> s2(2);
    cin >> s2;
    cout << s2 << endl;

    cout << "s1 = s2" << endl;
    s1 = s2;

    cout << "s1 != s2: " << (s1 != s2) << endl << endl;

    Array<double> d1(3);
    cin >> d1;
    cout << d1[2] << endl << endl;

    Array<char> c1(3);
    cin >> c1;
    c1[0] = 't';
    cout << c1;

    return 0;
}
