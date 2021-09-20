#include <iostream>
#include <string>

using namespace std;

template <class T>
bool compare(const T &value1, const T &value2) {
    return value1 == value2;
}

int main() {
    int i1 = 1;
    int i2 = 1;
    int i3 = 3;
    cout << "Inteiros:" << endl;
    cout << compare(i1, i2) << endl;
    cout << compare(i1, i3) << endl << endl;

    float f1 = 15.75;
    float f2 = 15.75;
    float f3 = 15.57;
    cout << "Floats:" << endl;
    cout << compare(f1, f2) << endl;
    cout << compare(f2, f3) << endl << endl;

    double d1 = 14.789;
    double d2 = 14.789;
    double d3 = 1.4789;
    cout << "Doubles:" << endl;
    cout << compare(d1, d2) << endl;
    cout << compare(d1, d3) << endl << endl;

    char c1 = 'a';
    char c2 = 'a';
    char c3 = 'b';
    cout << "Chars:" << endl;
    cout << compare(c1, c2) << endl;
    cout << compare(c2, c3) << endl << endl;

    string s1 = "abc";
    string s2 = "abc";
    string s3 = "acb";
    cout << "Strings:" << endl;
    cout << compare(s1, s2) << endl;
    cout << compare(s1, s3) << endl;

    return 0;
}
