#ifndef Stack_h
#define Stack_h 

#include <iostream>
#include "StackExceptions.h"

using std::cerr;
using std::endl;

template <class T>
class Stack 
{
public:
    Stack(int = 10);
    ~Stack();
    
    void push(const T &);
    void pop(T &);

    bool isEmpty() const { return position == 0; }
    bool isFull() const { return position == size; }

private:
    T *stack;
    int position, size;
};

template <class T>
Stack<T>::Stack(int size) {
    this->size = ((size > 0) ? size : 10);
    position = 0;

    stack = new T[this->size];
}

template <class T>
Stack<T>::~Stack() {
    delete [] stack;
}

template <class T>
void Stack<T>::push(const T &el) {
    try {
        if (isFull()) {
            throw EmptyStackException();
        }

        stack[position++] = el;
    } catch (EmptyStackException& e) {
        cerr << e.what() << endl;
    }
}

template <class T>
void Stack<T>::pop(T &el) {
    try {
        if (isEmpty()) {
            throw FullStackException();
        }

        el = stack[--position];
    } catch (FullStackException& e) {
        cerr << e.what() << endl;
    }
}

#endif
