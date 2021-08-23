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
    cout << l;

    return 0;
}
