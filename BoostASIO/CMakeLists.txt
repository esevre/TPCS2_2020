cmake_minimum_required(VERSION 3.16)

project(BoostASIO)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)

set(Boost_NO_SYSTEM_PATHS true)
set(Boost_USE_STATIC_LIBS OFF CACHE BOOL "use static libraries from Boost")
set(Boost_USE_MULITHREADED ON)

if (WIN32)
    # disable autolinking in boost
    add_definitions( -DBOOST_ALL_NO_LIB )

    # force all boost libraries to dynamic link
    # need this even though autolinking disabled above
    add_definitions( -DBOOST_ALL_DYN_LINK )

    # Windows definitions below not working, moved into code
    #    set(_WIN32_WINNT 0x0601) # Windows 7
    #    set(_WIN32_WINNT 0x0602) # Windows 8
    #    set(_WIN32_WINNT 0x0603) # Windows 8.1
    #        set(_WIN32_WINNT 0x0A00) # Windows 10
endif ()

include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostASIO main.cpp connection_test.hpp grab_site_simple.hpp)