#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    unsigned long inputSize = input.length();
    
    cout << setw(inputSize*2) << input << endl;

    return 0;
}
