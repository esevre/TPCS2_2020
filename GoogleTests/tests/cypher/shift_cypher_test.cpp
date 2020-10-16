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
    for (int letter = 0; letter < alphabet.size(); ++letter) {
        ASSERT_EQ(encodeAscii(alphabet[letter]), ascii_a + letter);
    }
}

class CaseChange : public ::testing::Test {
protected:

protected:
    virtual void SetUp() {
    }

    std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string non_alpha = "!@#$%^&*()_+1234567890-=[]{} ";
};

TEST_F(CaseChange, ToLowercase)
{
    for (int letter = 0; letter < alphabet.size(); ++letter) {
        const char converted = to_lowercase(ALPHABET[letter]);
        const char expected = alphabet[letter];
        ASSERT_EQ(converted, expected);
    }
}

TEST_F(CaseChange, ToUppercase)
{
    for (int letter = 0; letter < alphabet.size(); ++letter) {
        const char converted = to_uppercase(alphabet[letter]);
        const char expected = ALPHABET[letter];
        ASSERT_EQ(converted, expected);
    }
}
TEST_F(CaseChange, NonAlpha)
{
    for (int letter = 0; letter < non_alpha.size(); ++letter) {
        const char converted1 = to_uppercase(non_alpha[letter]);
        const char converted2 = to_lowercase(non_alpha[letter]);
        const char expected = non_alpha[letter];
        ASSERT_EQ(converted1, expected);
        ASSERT_EQ(converted2, expected);
    }
}

#include "../../../cypher/Point.hpp"
class PointEquality : public ::testing::Test {
protected:
    void SetUp() override {
        point_i1 = Point<int>{1,1};
        point_i2 = Point<int>{2,2};
        point_i3 = Point<int>{3,3};
        point_d1 = Point<double>{1.1,1.1};
        point_d2 = Point<double>{2.2,2.2};
        point_d3 = Point<double>{3.3,3.3};
        point_p1 = Point<Point<int>>{point_i1, point_i1};
        point_p2 = Point<Point<int>>{point_i2, point_i2};
        point_p3 = Point<Point<int>>{point_i3, point_i3};

    }

    void TearDown() override {
    }

public:
    Point<int> point_i1;
    Point<int> point_i2;
    Point<int> point_i3;
    Point<double> point_d1;
    Point<double> point_d2;
    Point<double> point_d3;
    Point<Point<int>> point_p1;
    Point<Point<int>> point_p2;
    Point<Point<int>> point_p3;
};


TEST_F(PointEquality, intTest)
{
    EXPECT_EQ(point_i1.x, point_i2.x/2);
    EXPECT_EQ(point_i1.y, point_i2.y/2);
    EXPECT_EQ(point_i1.x, point_i3.x/3);
    EXPECT_EQ(point_i1.y, point_i3.y/3);
}

TEST_F(PointEquality, PointIntTest)
{
    EXPECT_EQ(point_p1.x.x, point_p2.x.x/2);
    EXPECT_EQ(point_p1.y.y, point_p2.y.y/2);
    EXPECT_EQ(point_p1.x.x, point_p3.x.x/3);
    EXPECT_EQ(point_p1.y.y, point_p3.y.y/3);
}

TEST_F(PointEquality, doubleTest)
{
    EXPECT_EQ(point_d1.x, point_d2.x/2.0);
    EXPECT_EQ(point_d1.y, point_d2.y/2.0);
//    EXPECT_EQ(point_d1.x, point_d3.x/3.0);
//    EXPECT_EQ(point_d1.y, point_d3.y/3.0);
    EXPECT_DOUBLE_EQ(point_d1.x, point_d3.x/3.0);
    EXPECT_DOUBLE_EQ(point_d1.y, point_d3.y/3.0);
}

TEST_F(PointEquality, operatorEqualTestTrue)
{
    EXPECT_TRUE(point_i1 == point_i1);
    EXPECT_TRUE(point_i2 == point_i2);
    EXPECT_TRUE(point_i3 == point_i3);
    EXPECT_TRUE(point_p1 == point_p1);
    EXPECT_TRUE(point_p2 == point_p2);
    EXPECT_TRUE(point_p3 == point_p3);
    EXPECT_TRUE(point_d1 == point_d1);
    EXPECT_TRUE(point_d2 == point_d2);
    EXPECT_TRUE(point_d3 == point_d3);
}
TEST_F(PointEquality, operatorEqualTestFalse)
{
    EXPECT_FALSE(point_i1 == point_i2);
    EXPECT_FALSE(point_i2 == point_i3);
    EXPECT_FALSE(point_i3 == point_i1);
    EXPECT_FALSE(point_p1 == point_p2);
    EXPECT_FALSE(point_p2 == point_p3);
    EXPECT_FALSE(point_p3 == point_p1);
    EXPECT_FALSE(point_d1 == point_d2);
    EXPECT_FALSE(point_d2 == point_d3);
    EXPECT_FALSE(point_d3 == point_d1);
}



