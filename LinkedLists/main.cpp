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
        if (print_on_delete) {
            std::cout << "deleting node with value: " << value << std::endl;
        }
    }
public:
    Type    value;
    NodePtr next = nullptr;
    const bool print_on_delete = false;
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
    // deep copy constructor
    LinkedList(const LinkedList &list) {
        ConstNodePtr pos = list.first();
        while(pos) {
            push_back(pos->value);
            pos = pos->next;
        }
    }
    ~LinkedList() {
        if (head != nullptr)
        {
            delete head;
        }
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

    void merge_at_value(LinkedList &list2, const Type &val)
    {
        if (list2.empty()) { return; }
        if (empty()) {
            // logic here for our list empty, but list 2 is not empty
            head = list2.first();
            list2.reset_head();
            return;
        }
        NodePtr pos = head;
        while(pos->value != val && pos->next) {
            pos = pos->next;
        }
        NodePtr pos_next = pos->next;
        NodePtr l2_head = list2.first();
        NodePtr l2_tail = list2.first();
        while(l2_tail->next) {
            l2_tail = l2_tail->next;
        }

        pos->next = l2_head;
        l2_tail->next = pos_next;
        list2.reset_head();
    }

    // Lambda is a lambda function that takes a value of type Type and returns a bool
    template <class Lambda>
    void merge_at_lambda(LinkedList &list2, Lambda lambda)
    {
        if (list2.empty()) { return; }
        if (empty()) {
            // logic here for our list empty, but list 2 is not empty
            head = list2.first();
            list2.reset_head();
            return;
        }
        NodePtr pos = head;
        while(!lambda(pos->value) && pos->next) {
            pos = pos->next;
        }
        NodePtr pos_next = pos->next;
        NodePtr l2_head = list2.first();
        NodePtr l2_tail = list2.first();
        while(l2_tail->next) {
            l2_tail = l2_tail->next;
        }

        pos->next = l2_head;
        l2_tail->next = pos_next;
        list2.reset_head();
    }

    NodePtr      first()       { return head; }
    ConstNodePtr first() const { return head; }

    bool empty() const { return head==nullptr; }
public:
    NodePtr head = nullptr;
private:
    void reset_head(NodePtr node_ptr=nullptr) { head = node_ptr; }

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

template <class Type>
void merge_at_value(LinkedList<Type> &list1, LinkedList<Type> &list2, Type value)
{
    list1.merge_at_lambda(list2, [value](auto x){ return x == value; });
}

bool merge_test(bool print_lists = false){
    LinkedList<char> list01 {'A', 'B', 'C', 'D'};
    LinkedList<char> list02 {'1', '2', '3'};

    if (print_lists) {
        print(list01);
        print(list02);
    }

    //    list01.merge_at_lambda(list02, [](auto x) { return x > 'B'; });
    merge_at_value(list01, list02, 'B');

    // the head of list02 should be nullptr, otherwise return false
    if (!list02.empty()) { return false; }

    return true;
}



int main(){
    if (merge_test()) {
        std::cout << "merge test SUCCESS\n";
    } else {
        std::cout << "merge test FAILURE\n";
    }


}


