#include <iostream>
#include <string>
#include "stack.hpp"

int main(){

    Stack<std::string> s = Stack<std::string>();

    std::cout << "Push some data:\n";
    s.push("apple");
    s.push("banana");
    s.push("orange");
    s.push("grape");
    s.push("melon"); 
    s.push("strawberry");
    
    s.print();

    std::cout << "\nPop 2 data\n";

    s.pop();
    s.pop();

    s.print();

    std::cout << "\nPeek operation\n";
    std::cout << s.peek() << std::endl;

    std::cout << "current List\n";
    s.print();

}