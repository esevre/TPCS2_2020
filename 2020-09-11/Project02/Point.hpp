//
// Created by esevre on 9/11/2020.
//

#pragma once

#include <complex>
#include <iostream>

template <class Type>
class Point {
public:
    Point(Type x, Type y) : x(x), y(y) {}
    Point() = default;
//    Point(const Point &point) = default;
    Point(const Point &point) : x(point.x*10), y(point.y*10) {}
public:
    Type x{};
    Type y{};
};


// generic function to print Point objects
template <class Type>
void print(const Point<Type> &point)
{
    std::cout << "(" << point.x << ", " << point.y << ")\n";
}

// use a template specialization to print a complex point with the formatting I like
template <class ComplexType>
void print(const Point<std::complex<ComplexType>> &point) {
    std::cout << "("
              << point.x.real() << " + " << point.x.imag() << "i, "
              << point.y.real() << " + " << point.y.imag() << "i)\n";

}


