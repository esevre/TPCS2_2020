//
// Created by esevre on 11/4/2020.
//
#include <iostream>
#include "connection_test.hpp"

int main()
{
    std::string address01 = "216.58.200.78";
    std::string address02 = "127.0.0.1";

    if (connection_test(address01)) {
        std::cout << "connected to Google.com! yay\n";
    } else {
        std::cout << "failed to connect to Google.com\n";
    }

    if (connection_test(address02)) {
        std::cout << "connected to my own computer!\n";
    } else {
        std::cout << "failed to connect to my own computer\n";
        std::cout << "this is because I am not running a server!\n";
    }
}
