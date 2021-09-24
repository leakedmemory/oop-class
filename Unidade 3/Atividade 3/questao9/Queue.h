#ifndef Queue_h
#define Queue_h

#include <iostream>
#include "QueueExceptions.h"

using namespace std;

template <class T=int>
class Queue
{
    friend ostream &operator<<(ostream& out, const Queue& q) {
        for (int i = 0 ; i < q.length ; i++) {
            out << q.queue[i] << " ";
        }
        out << endl;

        return out;
    }

public:
    Queue(int size=5) {
        this->size = (size > 0 ? size : 5);
        queue = new T[this->size];
    }

    ~Queue() {
        delete [] queue;
    }

    void enqueue(const T& value) {
        try {
            if (this->length >= size) {
                throw FullQueueException();
            }

            queue[this->length++] = value;
        } catch (FullQueueException& e) {
            cerr << e.what() << endl;
        }

        // if (this->length < size) {
        //     queue[this->length] = value;
        //     this->length++;
        // } else {
        //     cout << "ERRO: fila cheia." << endl;
        // }
    }

    void dequeue() {
        try {
            if (this->length <= 0) {
                throw EmptyQueueException();
            }

            this->length--;
            T *newQueue = new T[this->size];

            for (int i = 0, j = 1; i < this->length, j <= this->length; i++, j++) {
                newQueue[i] = queue[j];
            }

            queue = newQueue;
        } catch (EmptyQueueException& e) {
            cerr << e.what() << endl;
        }

        // if (this->length > 0) {
        //     this->length--;
        //     T *newQueue = new T[this->size];

        //     for (int i = 0, j = 1; i < this->length, j <= this->length; i++, j++) {
        //         newQueue[i] = queue[j];
        //     }

        //     queue = newQueue;
        // } else {
        //     cout << "ERRO: fila vazia.";
        // }
    }

    T &operator[](int i) {
        if (i < 0 || i >= length) {
            cerr << "Erro: Indice " << i << " fora de faixa." << endl;
            exit(1);
        }

        return queue[i];
    }

private:
    int size;
    int length = 0;
    T *queue;
};

#endif
