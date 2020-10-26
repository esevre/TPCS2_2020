
#include <fstream>
#include <vector>

void write_file(std::string filename, std::vector<int> &vector)
{
    std::ofstream outfile(filename);
    for (const auto &data : vector) {
        outfile << data << "\n";
    }
}


int main() {
    std::vector<int> vec{1,2,3,4,5, 101, 202, 303};
    write_file("filename.txt", vec);
}