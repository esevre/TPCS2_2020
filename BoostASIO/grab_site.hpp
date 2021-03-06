//
// Created by esevre on 11/6/2020.
//

#pragma once

#include <chrono>
#include <iostream>
#include <sstream>
#include <vector>
#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>


std::vector<char> vBuffer(2*1024);

// Grab data and print to screen
void GrabSomeData(boost::asio::ip::tcp::socket & socket, std::stringstream &ss)
{
    socket.async_read_some(boost::asio::buffer(vBuffer.data(), vBuffer.size()),
                           [&](std::error_code ec, std::size_t length)
                           {
                               if (!ec)
                               {
                                   std::cout << "****    ****    ****    ****    ****    ****    ****    ****\n";
                                   std::cout << "**  Read " << length << " bytes\n";
                                   std::cout << "****    ****    ****    ****    ****    ****    ****    ****\n";
                                   for (int i = 0; i < length; ++i) {
//                                        std::cout << vBuffer[i];
                                       ss << vBuffer[i];
                                   }
                                   GrabSomeData(socket, ss);
                               }
                           }
    );
}



std::string grab_site(const std::string &address, const int port=80)
{
    namespace sys  = boost::system;
    namespace asio = boost::asio;
    // Always check for an error in the connection, never know if the server or network are down
    sys::error_code ec;

    // Need a context - for platform specific interface
    asio::io_context context;

    // Create busy work for the context
    asio::io_context::work idleWork(context);

    // Start running the context in a thread
    std::thread thrContext = std::thread([&](){ context.run(); });

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

    std::stringstream ss;
    if (socket.is_open()) {
        GrabSomeData(socket, ss);

        std::string sRequest =
                "GET /index.html HTTP/1.1\r\n"
                "Host: themodernrogue.com\r\n"
                "Connection: close\r\n\r\n";
        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

        // Code to pause thread
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(5000ms);

       context.stop();
       if(thrContext.joinable()) { thrContext.join(); }
    }
    return ss.str();
}

void grab_site_example()
{
    // ip address for modern rogue website
    std::string mrogue = "198.49.23.145";
    auto contents = grab_site(mrogue);
    std::cout << "program done\n";
    std::cout << "************************\n";
    std::cout << contents << std::endl;

}

