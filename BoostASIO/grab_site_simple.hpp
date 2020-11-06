//
// Created by esevre on 11/6/2020.
//
#pragma once

#include <chrono>
#include <iostream>
#include <vector>
#include <boost/asio.hpp>

void grab_site_simple(const std::string &address, const int port=80)
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
    } else {
        std::cout << "connected!\n" << std::endl;
    }

    if (socket.is_open()) {
        std::cout << "socket is open!" << std::endl;
        std::string sRequest =
                "GET /index.html HTTP/1.1\r\n"
                "Host: example.com\r\n"
                "Connection: close\r\n\r\n";
        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

        // Code to pause thread
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(200ms);

        std::size_t bytes = socket.available();
        std::cout << "bytes available: " << bytes << std::endl;

        if (bytes > 0) {
            std::vector<char> vBuffer(bytes);
            socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);
            std::cout << "buffer is:\n";
            for (auto c : vBuffer) {
                std::cout << c;
            }
            std::cout << std::endl;
        }


    }

}



