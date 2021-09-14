#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    unsigned int fahrenheit;
    cin >> fahrenheit;
    double celsius = 5 / 9. * (fahrenheit - 32);

    cout << endl << fixed;
    cout << "|---------------------|" << endl;
    cout << left << setw(12) << "|Temperatura:" << right << setw(10) <<
        "Valor|" << endl;
    cout << "|---------------------|" << endl;
    cout << left << setw(12) << setprecision(3) << setw(12) <<
        "|Fahrenheit:" << right << setw(10) <<
        static_cast <double> (fahrenheit) << "|" << endl;
    cout << left << setw(12) << setprecision(3) << "|Celsius:" << right <<
        setw(10) << celsius << "|" << endl;
    cout << "|---------------------|" << endl;

    return 0;
}
