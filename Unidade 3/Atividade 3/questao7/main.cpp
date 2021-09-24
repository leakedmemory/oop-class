#include <iostream>
#include <stdexcept>

using namespace std;

class Foo: public runtime_error
{
public:
    Foo(const string& e="Erro em Foo.") : runtime_error(e) {};
};

class Bar: public runtime_error
{
public:
    Bar(const string& e="Erro em Bar.") : runtime_error(e) {};
};

void throw_error(const string class_name="Bar") {
    if (class_name == "Foo") {
        throw Foo();
    } else if (class_name == "Bar") {
        throw Bar();
    }
}

int main() {
    try {
        throw_error("Foo");
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
    }

    try {
        throw_error();
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
