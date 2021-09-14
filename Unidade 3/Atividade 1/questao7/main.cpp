#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

string PATH = "hardware.dat";

struct IItem {
    int id;
    char name[100];
    unsigned int quantity;
    double price;
};

IItem items[] {
    {3, "Lixadeira", 7, 57.98},
    {17, "Martelo", 76, 11.99},
    {24, "SerraTico-tico", 21, 11.},
    {39, "CortadorDeGrama", 3, 79.5},
    {56, "SerraElétrica", 18, 99.99},
    {68, "ChaveDeFenda", 106, 6.99},
    {77, "Marreta", 11, 21.5},
    {83, "ChaveInglesa", 34, 7.5}
};

bool save_data(IItem items[], int length) {
    ofstream fout("hardware.dat", ios::out);

    if (!fout)
        return false;
    
    for (int index = 0; index < length; index++) {
        fout << items[index].id << ' ' << items[index].name << ' ' <<
            items[index].quantity << ' ' << items[index].price << endl;
    }

    fout.close();

    return true;
}

bool list_items() {
    ifstream fin("hardware.dat", ios::in);

    if (!fin)
        return false;
    
    IItem i;

    cout << "  ID   " << "       NOME        " << "QUANTIDADE " <<
        " PREÇO (R$) " << endl;

    cout << fixed;
    while (fin >> i.id >> i.name >> i.quantity >> i.price) {
        cout << left << setw(7) << i.id << ' ' << setw(18) << i.name <<
            setw(10) << i.quantity << setw(12) << right << setprecision(2) <<
            i.price << endl;
    }
    cout << defaultfloat;

    fin.close();

    return true;
}

void removeItem(string path, string itemID) {
    string line;
    ifstream fin;
    
    fin.open(path);
    ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line)) {
        if (line.find(itemID) == string::npos)
            temp << line << endl;
    }

    temp.close();
    fin.close();

    const char * p = path.c_str();
    remove(p);
    rename("temp.txt", p);
}

void addItem(string path, IItem item) {
    ofstream fout;
    ifstream fin;

    fin.open(path);
    fout.open(path, ios::app);

    if (fin.is_open()) {
        fout << item.id << ' ' << item.name << ' ' << item.quantity <<
            ' ' << item.price << endl;
    }

    fin.close();
    fout.close();
}

int main() {
    IItem newItem = { 40, "Furadeira", 5, 322. };

    save_data(items, 8);
    list_items();
    removeItem(PATH, "17");
    addItem(PATH, newItem);

    cout << endl;

    list_items();

    return 0;
}
