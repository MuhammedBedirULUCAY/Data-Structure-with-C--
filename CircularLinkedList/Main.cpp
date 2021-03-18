#include <iostream>
#include "CircularLinkedList.h"


int main(){


    CircularLinkedList cList = CircularLinkedList();

    std::cout << "\nadd(int _data):\n";
    cList.add(6);
    cList.add(13);
    cList.add(65);
    cList.add(5);
    cList.print();

    std::cout << "insert(int index,int _data)\n";
    cList.insert(4,26);
    cList.insert(0,22);
    cList.display();
    std::cout << std::endl;

    std::cout << "remove(int index)\n";
    cList.remove(3);
    cList.remove(0);
    cList.display();
    std::cout << std::endl;

    std::cout << "indexOf(*(new Node(5,nullptr)) = " << cList.indexOf(*(new Node(5,nullptr))) << std::endl;
    std::cout << std::endl;

    std::cout << "remove(*(new Node(int data,nullptr)))\n";
    cList.remove(*(new Node(5,nullptr)));
    cList.display();
    std::cout << std::endl;

    std::cout << "reverse()\n";
    cList.reverse();
    std::cout << std::endl;
    cList.display();
    std::cout << std::endl;

    std::cout << "adress\n";
    cList.displayAdress();
}