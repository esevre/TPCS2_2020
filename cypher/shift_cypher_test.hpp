//
// Created by esevre on 10/14/2020.
//
#pragma once

#include <vector>
#include <iostream>
#include <string>



int encodeAscii(char c) {
    return static_cast<int>(c);
}
char encodeAscii(int i) {
    return static_cast<char>(i);
}

char to_uppercase(char c) {
    const int a = encodeAscii('a');
    const int z = encodeAscii('z');
    if (c >= a && c <= z) {
        const int A = encodeAscii('A');
        const int diff = a-A;
        return encodeAscii(c - diff);
    }
    return c;
}

char to_lowercase(char c) {
    const int A = encodeAscii('A');
    const int Z = encodeAscii('A');
    if (c >= A && c <= Z) {
        const int a = encodeAscii('A');
        const int diff = a-A;
        return encodeAscii(c + diff);
    }
    return c;
}

int encodeSimpleShift(char c)
{
    const char a = 'a';
    const char z = 'z';
    const char A = 'A';
    const char Z = 'Z';

    // if UPPERCASE:
    if ( c <= Z && c >= A ) {
        return encodeAscii(c) - encodeAscii(A);
    }
    // if lowercase:
    if ( c <= z && c >= a ) {
        return encodeAscii(c) - encodeAscii(a);
    }
    return -1;
}







