//
// Created by esevre on 10/16/2020.
//
#pragma once


#include <iostream>

template <class Type>
struct Point {
//    Point() : x(Type()), y(Type()) {}
    bool operator==(const Point &rhs) const {
        return (this->x == rhs.x) && (this->y == rhs.y);
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
    Type x, y;
};







