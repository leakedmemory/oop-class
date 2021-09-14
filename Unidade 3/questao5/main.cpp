#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "|------------|" << endl;
    for (int character = 33; character <= 126; character++) {
        cout << "|ASCII " << setw(3) << character << "  ";
        cout.put(character) << "|" << endl;
    }
    cout << "|------------|" << endl;

    return 0;
}
