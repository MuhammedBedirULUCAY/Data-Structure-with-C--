#include <iostream>
#include "stack.h"

template<typename T>
Node<T>::Node() 
    : data(NULL), next(nullptr)
{           }

template<typename T>
Node<T>::Node(T _data,Node<T> *_next)
    : data(_data), next(_next)
{           }

template<typename T>
Stack<T>::Stack()
    : size(0), head(nullptr)
{               }

template<typename T>
bool Stack<T>::push(T _data){

    if(head == nullptr)
        head = new Node<T>(_data,nullptr);
    else{
        Node<T> * tmpH = new Node<T>(_data,head);
        head = tmpH;
    }

    size++;
}

template<typename T>
T Stack<T>::pop(){
    T tmp = head->data;
    head = head->next;
    size--;
    return tmp;
}

template<typename T>
T Stack<T>::peek(){
    return head->data;
}

template<typename T>
bool Stack<T>::isEmpty(){
    return size == 0;
}

template<typename T>
void Stack<T>::print(){

    Node<T> * iter = head;

    while(iter->next != nullptr){
        std::cout << iter->data << " -> ";
        iter = iter->next;
    }
    std::cout << iter->data << std::endl; 

}




