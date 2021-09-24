#include <iostream>
#include "Stack.h"

using std::cout;

int main() {
    Stack<int> si(3);
    int popEli;
    si.push(1);
    si.push(2);
    si.push(3);
    si.push(4);
    si.pop(popEli);
    si.pop(popEli);
    si.pop(popEli);
    si.pop(popEli);

    cout << endl;

    Stack<string> ss(3);
    string popEls;
    ss.push("banana");
    ss.push("uva");
    ss.push("melancia");
    ss.push("goiaba");
    ss.pop(popEls);
    ss.pop(popEls);
    ss.pop(popEls);
    ss.pop(popEls);

    return 0;
}
