//
// Created by esevre on 9/11/2020.
//

#include <iostream>

template <class Type>
class Point {
public:
    Point(Type x, Type y) : x(x), y(y) {
//        Point::x = x;  // Class Resolution Operator
//        this->y = y;   // this pointer to access members
    }
public:
    Type x{};
    Type y{};
};

template <class Type>
void print(const Point<Type> &point)
{
    std::cout << "(" << point.x << ", " << point.y << ")\n";
}


int main(){
    Point<int> p{1,2};
    print(p);
    return p.x;
}
