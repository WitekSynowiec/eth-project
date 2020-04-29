//
// Created by Witold Synowiec on 27/04/2020.
//
#include "gtest/gtest.h"
#include "../com/main.cpp"

/**
 * In odrer to add new tests copy
    TEST(TestApp, test1) {
    expr1 = "2x^3+4x^6";
    expr2 = "5x^3-2x^6";
    EXPECT_EQ(addExpression(expr1, expr2), std::string("7x^3+2x^6"));
    }
    and add it at the end of the file. Remember to change test name from test1 as it is not possible to run two same-name test

    In order to receive good answer remember that alghoritm merge two strings, expr1 and expr2 and reorganises them in manner in which variable count of the first occurance is augmented or diminished, while second is removed.
    I.e. 2x^3+4x^6; 5x^3-2x^6 first step will me: 2x^3+4x^6 + 5x^3-2x^6 and next 7x^3+4x^6  -  2x^6 which is the result.
 */


std::string expr1;
std::string expr2;

TEST(TestApp, test1) {
    expr1 = "2x^3+4x^6";
    expr2 = "5x^3-2x^6";
    EXPECT_EQ(addExpression(expr1, expr2), std::string("7x^3+2x^6"));
}
TEST(TestApp, test2) {
    expr1 = "-2.2x^3+4x^6";
    expr2 = "5x^31+2x^8";
    EXPECT_EQ(addExpression(expr1, expr2), std::string("-2.2x^3+4x^6+5x^31+2x^8"));
}
TEST(TestApp, test3) {
    expr1 = "-2x^3+4x^6-5";
    expr2 = "5x^3-2x^6";
    EXPECT_EQ(addExpression(expr1, expr2), std::string("3x^3+2x^6-5"));
}

TEST(TestApp, test4) {
    expr1 = "-2.2x^-3.4+4x^6";
    expr2 = "5x^3-2.35x^-3.4";
    EXPECT_EQ(addExpression(expr1, expr2), std::string("-4.55x^-3.4+4x^6+5x^3"));
}

TEST(TestApp, test5) {
    expr1 = "2x^3+4x^6-y^3";
    expr2 = "5x^3-2x^6";
    EXPECT_EQ(addExpression(expr1, expr2), std::string("7x^3+2x^6-y^3"));
}

TEST(TestApp, test6) {
    expr1 = "x^3+x+2x^7";
    expr2 = "x^3-2x^6";
    EXPECT_EQ(addExpression(expr1,expr2),std::string("2x^3+x+2x^7-2x^6"));
}

TEST(TestApp, test7) {
    expr1 = "x^3+x+2x^76";
    expr2 = "-x^3-2x^6";
    EXPECT_NE(addExpression(expr1,expr2),std::string("2x^3+x+2x^7-2x^6"));
}

TEST(TestApp, test8) {
    expr1 = "-x^3+x+2x^76";
    expr2 = "-x^3-2x^6";
    EXPECT_NE(addExpression(expr1,expr2),std::string("2x^3+2x^-9-x+2x^7-2x^6"));
}

TEST(TestApp, test9) {
    expr1 = "-x^3+x+2x^-76";
    expr2 = "-x^3-2x^6";
    EXPECT_NE(addExpression(expr1,expr2),std::string("2x^3+x+2x^7-2x^6-3x^7"));
}

TEST(TestApp, test10) {
    expr1 = "-2x^34+x+2x^-76";
    expr2 = "-x^3-24x^6";
    EXPECT_NE(addExpression(expr1,expr2),std::string("-32x^5+x+22x^7-2x^6-3x^7"));
}