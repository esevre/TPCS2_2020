//
// Created by esevre on 11/4/2020.
//
#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#include <iostream>
#include "connection_test.hpp"
#include "grab_site_simple.hpp"
#include "grab_site.hpp"
#include "grab_site_advanced.hpp"

int main()
{
    grab_site_advanced_example();
}

