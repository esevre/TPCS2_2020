//
// Created by esevre on 10/14/2020.
//
#include "gtest/gtest.h"

#include "../../../cypher/shift_cypher_test.hpp"

#include <string>

TEST(EncodingAscii, AsciiAtoZ)
{
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    const int ascii_A = 65;
    const int ascii_a = 97;
}

TEST(CaseChange, ToLowercase)
{
    std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int letter = 0; letter < alphabet.size(); ++letter) {
        const char converted = to_lowercase(ALPHABET[letter]);
        const char expected = alphabet[letter];
        EXPECT_EQ(converted, expected);
    }

}

TEST(CaseChange, ToUppercase)
{
    std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int letter = 0; letter < alphabet.size(); ++letter) {
        const char converted = to_uppercase(alphabet[letter]);
        const char expected = ALPHABET[letter];
        EXPECT_EQ(converted, expected);
    }
}

