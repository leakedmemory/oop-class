#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct IType {
    char type[20];
    int size;
};

IType types[] = {
    {"Char", sizeof(char)},
    {"UnsignedChar", sizeof(unsigned char)},
    {"SignedChar", sizeof(signed char)},
    {"Int", sizeof(int)},
    {"UnsignedInt", sizeof(unsigned int)},
    {"SignedInt", sizeof(signed int)},
    {"ShortInt", sizeof(short int)},
    {"UnsignedShortInt", sizeof(unsigned short int)},
    {"SignedShortInt", sizeof(signed short int)},
    {"LongInt", sizeof(long int)},
    {"SignedLongInt", sizeof(signed long int)},
    {"UnsignedLongInt", sizeof(unsigned long int)},
    {"LongLongInt", sizeof(long long int)},
    {"UnsignedLongLongInt", sizeof(unsigned long long int)},
    {"Float", sizeof(float)},
    {"Double", sizeof(double)},
    {"LongDouble", sizeof(long double)},
    {"Wchar_t", sizeof(wchar_t)}
};

bool save_data(IType types[], int length) {
    ofstream fout("dados.dat", ios::out);

    if (!fout)
        return false;
    
    for (int index = 0; index < length; index++) {
        fout << types[index].type << ' ' << types[index].size << endl;
    }

    fout.close();

    return true;
}

bool list_types() {
    ifstream fin("dados.dat", ios::in);

    if (!fin)
        return false;
    
    IType t;

    cout << "        TIPO       " << "  TAMANHO" << endl;

    while (fin >> t.type >> t.size) {
        cout << left << setw(19) << t.type << ' ' << setw(8) << right <<
            t.size << endl;
    }

    fin.close();

    return true;
}

int main() {
    save_data(types, 18);
    list_types();

    return 0;
}
