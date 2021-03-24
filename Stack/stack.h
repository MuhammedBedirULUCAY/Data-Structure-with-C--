#ifndef S_H
#define S_H

#include "stack.h"

template<typename T>
class Node{

    public:
        T data;
        Node<T> * next;

        Node();
        Node(T _data,Node *_next);

};

template<typename T>
class Stack{

    public:
        Stack();

        T peek();
        T pop();
        bool push(T _data);
        bool isEmpty();

        void print();

    private:
        Node<T> * head;
        int size;
};

#endif