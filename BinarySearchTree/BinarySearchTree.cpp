#include <iostream>
#include"BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() 
    : root(nullptr),iter(nullptr)
{                         }

bool BinarySearchTree::add(int _data){
    root = add(root,_data);
    iter = root;
}

Node* BinarySearchTree::add(Node* root,int _data){

    if(root == nullptr)
        return new Node(_data);
   
    if(root->data < _data)
        root->right = add(root->right, _data);

    if(root->data > _data)
        root->left = add(root->left, _data);

    return root;    
}

void BinarySearchTree::printBT(){
    iter = root;
    printBT("",iter,false);
}

void BinarySearchTree::printBT(const std::string& prefix, const Node *local,bool isLeft){

    if(local != nullptr){
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "'--");
    
        std::cout << local->data << std::endl;

        printBT(prefix + (isLeft ? "|   " : "    "), local->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), local->right, false);
    }
}

int BinarySearchTree::sum(){
    iter = root;    
    return sum(iter);
}

int BinarySearchTree::sum(Node* local){

    if(local == nullptr)
        return 0;

    return local->data +sum(local->left) + sum(local->right); 
}

bool BinarySearchTree::query(int _data){
    iter = root;
    return query(iter, _data);

}

bool BinarySearchTree::query(Node* local, int _data){

    if(local == nullptr)
        return false;
    else if(_data == local->data)
        return true;
    else{
        bool leftSide = query(local->left, _data);
        if(leftSide)
            return true;
        return query(local->right , _data);
    }
}

void BinarySearchTree::nodeWay(int _data){
    if(query(_data)){
        iter = root;
        nodeWay(iter, _data);
    }
    else
        std::cout << "Tree has not " << _data;
}

void BinarySearchTree::nodeWay(Node * local,int _data){

    if(_data == local->data){
        std::cout << _data;
        return;
    }

    if(local->data > _data){
        std::cout << "Left => ";
        nodeWay(local->left, _data);
    }
    if(local->data < _data){
        std::cout << "Right => ";
        nodeWay(local->right, _data);
    }
}
