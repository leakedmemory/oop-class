#include "Complex.h"

int main() 
{
    Complex k(5, -3);
    Complex l(-2, 7);

    cout << k;
    cout << l << endl;

    Complex m = k + l;
    k += l;

    cout << m;
    cout << k << endl;

    cout << ++k;
    cout << l++;
    cout << l << endl;

    Complex n(10, -6);
    Complex o = m - n;

    cout << m;
    cout << n;
    cout << o << endl;

    o -= n;
    cout << o;
    cout << --n;
    cout << o--;
    cout << o;

    return 0;
}
