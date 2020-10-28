#include <iostream>
#include <fstream>
#include <vector>

#include "stream_examples/file_io.hpp"

int main() {
    std::vector<int> vec{ 1, 2, 3, 4, 5, 10, 20, 30, 40, 50};
//    write_file("../filename.txt", vec);
    auto file_vec = read_file_vec("../filename.txt");

    for (const auto &elt : vec) {
        std::cout << elt << ", ";
    }

}