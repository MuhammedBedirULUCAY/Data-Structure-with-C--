#include "Node.h"

Node::Node() : Node(0)
{                   }

Node::Node(int _data) 
    : data(_data),left(nullptr),right(nullptr)
{                   }