//
// Created by esevre on 10/27/2020.
//
#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <array>

auto file_size(std::string filename)
{
    std::ifstream infile(filename, std::ios::binary | std::ios::ate);
    return infile.tellg();
}

std::vector<int> read_file_vec(std::string filename)
{
    std::vector<int> data_vec;
    int data;
    std::ifstream infile(filename);
    while (infile.good()) {
        infile >> data;
        if (infile.good()) {
            data_vec.push_back(data);
        }
    }
    return data_vec;
}

std::string read_file_as_string(std::string filename){
    std::string contents;
    size_t file_sz = file_size(filename);
    contents.resize(file_sz);

    std::ifstream infile(filename);
    infile.read(contents.data(), file_sz);
    return contents;
}

// Will write vector to file if "Type" has operator<< overload for ostream
template <class Type>
void write_file(std::string filename, std::vector<Type> &vector)
{
    std::ofstream outfile(filename);
    for (const auto &data : vector) {
        outfile << data << "\n";
    }
}











