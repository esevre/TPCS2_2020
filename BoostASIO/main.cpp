//
// Created by esevre on 11/4/2020.
//
#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#include <iostream>
#include "connection_test.hpp"
#include "grab_site_simple.hpp"

int main()
{
    std::string address01 = "93.184.216.34";
    grab_site_simple(address01);
}

