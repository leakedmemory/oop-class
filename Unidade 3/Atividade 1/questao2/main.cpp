#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double number = 100.453627;

    cout << fixed;
    cout << setprecision(1) << "1 casa:  " << number << endl;
    cout << setprecision(2) << "2 casas: " << number << endl;
    cout << setprecision(3) << "3 casas: " << number << endl;
    cout << setprecision(4) << "4 casas: " << number << endl;

    return 0;
}
