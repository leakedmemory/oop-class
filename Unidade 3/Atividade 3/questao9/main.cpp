#include <iostream>
#include "Queue.h"

int main() {
    Queue i1(3);
    i1.enqueue(1);
    i1.enqueue(2);
    i1.enqueue(3);
    i1.enqueue(4);
    i1.dequeue();
    i1.dequeue();
    i1.dequeue();
    i1.dequeue();

    cout << endl;

    Queue<string> s1(3);
    s1.enqueue("banana");
    s1.enqueue("uva");
    s1.enqueue("melancia");
    s1.enqueue("goiaba");
    s1.dequeue();
    s1.dequeue();
    s1.dequeue();
    s1.dequeue();

    cout << endl;

    Queue<char> c1(3);
    c1.enqueue('a');
    c1.enqueue('b');
    c1.enqueue('c');
    c1.enqueue('d');
    c1.dequeue();
    c1.dequeue();
    c1.dequeue();
    c1.dequeue();

    return 0;
}
