#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue i1(5);
    i1.enqueue(1);
    i1.enqueue(2);
    i1.enqueue(3);
    cout << i1;
    i1.dequeue();
    cout << i1;
    i1.enqueue(5);
    cout << i1 << endl;;

    Queue<string> s1(3);
    s1.enqueue("banana");
    s1.enqueue("uva");
    s1.enqueue("melancia");
    cout << s1;
    s1.enqueue("goiaba");
    s1.dequeue();
    s1.enqueue("goiaba");
    cout << s1 << endl;

    Queue<char> c1(3);
    c1.enqueue('a');
    c1.enqueue('b');
    cout << c1;
    c1.dequeue();
    c1.dequeue();
    c1.dequeue();
    cout << c1;

    return 0;
}
