#include <iostream>
#include "BinarySearchTree.h"

int main(){

    BinarySearchTree BTree = BinarySearchTree();

    BTree.add(8);    
    BTree.add(5);    
    BTree.add(10);    
    BTree.add(11);    
    BTree.add(6);    
    BTree.add(9);
    BTree.add(2);
    
    BTree.printBT();

    std::cout << "Query 7 :"  << BTree.query(7) << std::endl;
    std::cout << "Query 2 :"  << BTree.query(2) << std::endl;
    std::cout << "Query 6 :"  << BTree.query(6) << std::endl;
    std::cout << "Query 9 :"  << BTree.query(9) << std::endl;
    std::cout << "Query 11 :" << BTree.query(11) << std::endl;
    std::cout << std::endl;
    

    std::cout << "way of 7: ";
    BTree.nodeWay(7);
    std::cout << std::endl;

    std::cout << "way of 2: ";
    BTree.nodeWay(2);
    std::cout << std::endl;
    
    std::cout << "way of 6: ";
    BTree.nodeWay(6);
    std::cout << std::endl;

    std::cout << "way of 9: ";
    BTree.nodeWay(9);
    std::cout << std::endl;
    
    std::cout << "way of 11: ";
    BTree.nodeWay(11);
    std::cout << std::endl;

    std::cout << "Sum of Tree : " << BTree.sum();

    return 0;
}


