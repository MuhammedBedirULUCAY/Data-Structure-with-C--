#ifndef BST
#define BST


#include "Node.h"

class BinarySearchTree{

    public:

        BinarySearchTree();

        bool add(int _data);
        Node* add(Node* local,int _data);

        void printBT();
        void printBT(const std::string& prefix, const Node *local, bool isLeft);

        int sum();
        int sum(Node* local);

        bool query(int _data);
        bool query(Node *local ,int _data);
        
        void nodeWay(int _data);
        void nodeWay(Node * local,int _data);
        
    private:
        Node * iter;
        Node * root = new Node(3);
};

#endif