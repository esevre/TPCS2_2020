//
// Created by esevre on 9/11/2020.
//

#include <iostream>
#include <complex>
#include <vector>
#include <array>

#include "Point.hpp"

int main()
{
    // show difference between copying and creating in place
    Point<int> p0 = Point<int>(9,9);
    print(p0);

    std::vector<Point<int>> int_points;
    const int vec_size = 10;
    int_points.reserve(vec_size*2);

    for (int i = 0; i < vec_size; ++i) {
        // pushes an object onto the end of a vector
        int_points.push_back( Point<int>(i, 2*i) );
        // creates an object with given parameters at the end of a vector
        int_points.emplace_back(i, 2*i);
    }
    // C++11 (and newer) range based for loop
    //    similar to pythonic:   for point in container
    for (const auto &point : int_points) {
        print(point);
    }

    std::cout << "********************************\n";
    // Looking at arrays
    std::array<Point<int>, vec_size> p_array;
    for (auto &point : p_array) {
        point.x = 3;
        point.y = 4;
    }
    for (const auto &point : p_array) {
        print(point);
    }

}
