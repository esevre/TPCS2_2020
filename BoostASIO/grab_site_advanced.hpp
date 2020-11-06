//
// Created by esevre on 11/6/2020.
//
//  This isn't code from class, but some modifications
//    I made to the class code to make it easier.
#pragma once

#include <chrono>
#include <iostream>
#include <sstream>
#include <vector>
#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

struct SiteInfo {
    SiteInfo(const std::string ip, const std::string url, const int port=80)
        : site_ip(ip), site_url(url), port(port)
    {}
    std::string site_ip;
    std::string site_url;
    int port = 80;
};

struct DataGrabber {
    using Socket = boost::asio::ip::tcp::socket;
    using OStream = std::ostream;
    DataGrabber() = delete;
    DataGrabber(const DataGrabber&) = delete;

    DataGrabber(Socket & socket, OStream &ostream) : vBuffer(num_units * unit)
    {
        GrabSomeData(socket, ostream);
    }

// Grab data and print to screen
    void GrabSomeData(Socket & socket, OStream &ostream)
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
                                           ostream << vBuffer[i];
                                       }
                                       GrabSomeData(socket, ostream);
                                   }
                               }
        );
    }

public:
    const std::size_t unit = 1024;
    const std::size_t num_units = 2;
    std::vector<char> vBuffer;
};



std::string grab_site_advanced(const SiteInfo &site_info)
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
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address(site_info.site_ip, ec), site_info.port);
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
        DataGrabber dataGrabber(socket, ss);

        std::string sRequest =
                "GET /index.html HTTP/1.1\r\n"
                "Host: " + site_info.site_url + "\r\n"
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


void grab_site_advanced_example()
{
    std::string mrogue = "198.49.23.145";
    auto contents = grab_site_advanced({mrogue, "themodernrogue.com"});
    std::cout << "program done\n";
    std::cout << "************************\n";
    std::cout << contents << std::endl;

}


