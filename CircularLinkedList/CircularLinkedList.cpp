#include "CircularLinkedList.h"

Node::Node()
{   }

Node::Node(int _data, Node * point) :
    data(_data)
{            next = point;            }

CircularLinkedList::CircularLinkedList() :
    head(nullptr), iter(head), size(0)
{                    }

bool CircularLinkedList::insert(int index, int _data){

    if(index < 0 || index > size)
        return false;
    
    if(index == 0){
        Node *newHead = new Node(_data,head);
        Node* lastNode = getNode(size-1);
        lastNode->next = newHead;
        head = newHead;
    }else{
        Node* node = getNode(index-1);
        Node* newNode = new Node(_data,node->next);
        node->next = newNode;
    }
    size++;
    return true;
}

Node* CircularLinkedList::getNode(int index){
    if(index >= size)
        return nullptr;
    
    iter = head;
    for(int i=0; i<index;++i)
        iter = iter->next;
  
    return iter;    
}

bool CircularLinkedList::add(int _data){

    if(head == nullptr){
        head = new Node(_data,nullptr);
        head->next = head;
    }
    else{
        iter = head;
        
        for(;iter->next != head;)
            iter = iter->next;
        
        iter->next = new Node(_data,head);
    }     
    size++;
}

bool CircularLinkedList::removeNext(Node* node){

    Node* tmp = node->next;
    node->next = node->next->next;
   
    delete tmp;
   
    return true;
}

bool CircularLinkedList::removeHead(){

    Node * tmp = head;
    head = head->next;
    getNode(size-2)->next = head;
    delete tmp;
    
    return true;
}

bool CircularLinkedList::remove(int index){
    if(index < 0 || index > size)
        return false;

    if(index == 0)
        removeHead();
    else    
        removeNext(getNode(index-1));
    size--;
    return true;    
}

bool CircularLinkedList::remove(const Node& node){

    int index = indexOf(node);
    if(index == -1)
        return false;

    remove(index);
    return true;
}

int CircularLinkedList::indexOf(const Node& node){
    iter = head;

    for(int i=0; i<size; ++i, iter = iter->next){
        if(iter->data == node.data)
            return i;
    }
    return -1;
}

void CircularLinkedList::reverse(){
    
    Node* prevNode = nullptr; 
    Node* currentNode = head; 
    Node* nextNode; 
    do { 
        nextNode = currentNode->next; 
        currentNode->next = prevNode; 
        prevNode = currentNode; 
        currentNode = nextNode;
    }while (currentNode != (head)); 
  
    head->next = prevNode; 
    head = prevNode;
}

void CircularLinkedList::display(){
    iter = head->next;

    std::cout << "-> " << head->data;

    for(; iter != head; iter = iter->next){
        std::cout << "-> " << iter->data;
    }
    std::cout << std::endl;
}

void CircularLinkedList::print(){
    iter = head;

    for(int i=0; i<size; ++i, iter = iter->next)
        std::cout << "-> "<< iter->data;
    
    std::cout << std::endl;
}

void CircularLinkedList::displayAdress(){
    
    iter = head;
    for(int i=0; i<size; ++i, iter = iter->next)
        std::cout << iter << "(" << iter->data << ")" << " next : " << iter->next << std::endl;
    
    std::cout << std::endl;
}
