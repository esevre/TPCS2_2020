//
// Created by esevre on 11/6/2020.
//
#pragma once

#include <iostream>
#include <boost/asio.hpp>

bool connection_test(const std::string &address, const int port = 80)
{
    namespace sys  = boost::system;
    namespace asio = boost::asio;
    // Always check for an error in the connection, never know if the server or network are down
    sys::error_code ec;

    // Need a context - for platform specific interface
    asio::io_context context;
    // endpoint is the server we want to connecto, and the port
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address(address, ec), port);
    // Create a socket, the context will deliver the implementation
    asio::ip::tcp::socket socket(context);
    // Tell the socket to try and connect
    socket.connect(endpoint, ec);
    // If error
    if (ec) {
        std::cout << "Failed to connect:\n" << ec.message() << std::endl;
        return false;
    }
    std::cout << "connected!\n" << std::endl;
    return true;
}


void run_simple_test()
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



