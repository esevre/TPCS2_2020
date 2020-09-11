//
// Created by esevre on 9/11/2020.
//

#include <iostream>
#include <complex>
#include <vector>

template <class Type>
class Point {
public:
    Point(Type x, Type y) : x(x), y(y) {}
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

int main()
{
    std::vector<Point<int>> int_points;
    const int vec_size = 10;
    int_points.reserve(vec_size*2);
    for (int i = 0; i < vec_size; ++i) {
        // pushes an object onto the end of a vector
        int_points.push_back( Point<int>(i, 2*i) );
        // creates an object with given parameters at the end of a vector
        int_points.emplace_back(i, 2*i);
    }
    for (const auto &point : int_points) {
        print(point);
    }

}
