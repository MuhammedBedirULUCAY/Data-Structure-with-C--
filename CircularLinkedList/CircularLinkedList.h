#ifndef CList
#define CList

#include <iostream>

class Node{
    public:
        int data;
        Node *next;
        Node();
        Node(int _data,Node *point);
};

class CircularLinkedList{
    public:

        CircularLinkedList();
       
        bool add(int _data);
        bool insert(int index,int _data);

        bool remove(int index);
        bool remove(const Node& node);

        int indexOf(const Node& node);

        void reverse();
        Node* reverse(Node* local);

        void print();
        void display();
        void displayAdress();

    private:
        bool removeNext(Node* node);
        bool removeHead();
        Node* getNode(int index);
        
        Node* head;
        Node* iter;
        int size;
};

#endif 