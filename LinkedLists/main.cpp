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
    ~Node(){
        if (next != nullptr) {
            delete next;
        }
        std::cout << "deleting node with value: " << value << std::endl;
    }

    // this -> old next
    //         new node -> old next    : complete in line 22
    // this -> new node                : complete in line 23
    void insert_after(const Type &val) {
        NodePtr node = new NodeBase(val, next);
        next = node;
    }
public:
    Type    value;
    NodePtr next = nullptr;
};

template <class Type>
void print(const Node<Type> * node) {
    const Node<Type> *pos = node;
    while (pos!=nullptr) {
        std::cout << pos->value << ", ";
        pos = pos->next;
    }
    std::cout << std::endl;
}

int main(){
    Node<double> *n1 = new Node<double>(1.1);
    n1->insert_after(2.2);
    n1->insert_after(3.3);
    n1->insert_after(4.4);
    n1->insert_after(5.5);
    n1->insert_after(6.6);

    print(n1);

    delete n1;
}


