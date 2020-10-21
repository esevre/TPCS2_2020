//
// Created by esevre on 10/21/2020.
//
#include <iostream>

template <class Type>
struct Node{
public:
    using NodeBase     = Node<Type>;
    using NodePtr      = NodeBase*;
    using ConstNodePtr = const NodePtr;
public:
    Node() = default;
    Node(const Type &value, NodePtr next_node = nullptr)
        : value(value), next(next_node)
    {}
public:
    Type    value;
    NodePtr next = nullptr;
};

int main(){

}
