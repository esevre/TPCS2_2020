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
        if (verbose) {
            std::cout << "deleting node with value: " << value << std::endl;
        }
    }
public:
    Type    value;
    NodePtr next = nullptr;
    const bool verbose = false;
};

template <class Type>
class LinkedList {
public:
    using NodeType     = Node<Type>;
    using NodePtr      = NodeType *;
    using ConstNodePtr = const NodePtr;
    using LinkedListType = LinkedList<Type>;
    using LinkedListRef  = LinkedListType &;
public:
    LinkedList() = default;
    LinkedList(const std::initializer_list<Type> &list)
    {
        for (const auto & val : list) {
            push_back(val);
        }
    }
    ~LinkedList() {
        if (head) { delete head; }
    }

    LinkedListRef push_back(const Type &val)
    {
        if (head) {
            NodePtr pos = head;
            while (pos->next) {
                pos = pos->next;
            }
            pos->next = new NodeType(val);
        } else {
            head = new NodeType(val);
        }
        return *this;
    }

    NodePtr      first()       { return head; }
    ConstNodePtr first() const { return head; }

public:
    NodePtr head = nullptr;
};

// archived code
template <class Type>
void print(const Node<Type> * node) {
    const Node<Type> *pos = node;
    while (pos!=nullptr) {
        std::cout << pos->value << ", ";
        pos = pos->next;
    }
    std::cout << std::endl;
}

template <class Type>
void print(const LinkedList<Type> &list) {
    typename LinkedList<Type>::NodePtr pos = list.first();
    while (pos) {
        std::cout << pos->value << ", ";
        pos = pos->next;
    }
    std::cout << std::endl;
}

int main(){
//    Node<double> *n1 = new Node<double>(1.1);
//    n1->insert_after(2.2);
//    n1->insert_after(3.3);
//    n1->insert_after(4.4);
//    n1->insert_after(5.5);
//    n1->insert_after(6.6);

    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3).push_back(4);

    LinkedList<double> list_d {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    print(list);
    print(list_d);

//    print(n1);
//    delete n1;

}


