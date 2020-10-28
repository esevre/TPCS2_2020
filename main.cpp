
#include <fstream>
#include <vector>

#include "stream_examples/file_io.hpp"

int main() {
    std::vector<int> vec{ 1, 2, 3, 4, 5, 10, 20, 30, 40};
    write_file("../filename.txt", vec);
}