//
// Created by Witold Synowiec on 27/04/2020.
//
#include "gtest/gtest.h"
#include "../com/main.cpp"

TEST(TestApp, test){
std::string expr1;
std::string expr2;
std::string precise_res;

expr1 = "2x^3+4x^6";
expr2 = "5x^3-2x^6";
precise_res = "7x^3+2x^6";
EXPECT_EQ(addExpression(expr1,expr2),precise_res);

expr1 = "-2.2x^3+4x^6";
expr2 = "5x^31+2x^8";
precise_res = "-2.2x^3+4x^6+5x^31+2x^8";
EXPECT_EQ(addExpression(expr1,expr2),precise_res);

expr1 = "-2x^3+4x^6-5";
expr2 = "5x^3-2x^6";
precise_res = "3x^3+2x^6-5";
EXPECT_EQ(addExpression(expr1,expr2),precise_res);

expr1 = "-2.2x^-3.4+4x^6";
expr2 = "5x^3-2.35x^-3.4";
precise_res = "-4.55x^-3.4+4x^6+5x^3";
EXPECT_EQ(addExpression(expr1,expr2),precise_res);

expr1 = "2x^3+4x^6-y^3";
expr2 = "5x^3-2x^6";
precise_res = "7x^3+2x^6-1y^3";
EXPECT_EQ(addExpression(expr1,expr2),precise_res);

expr1 = "x^3+x+2x^7";
expr2 = "x^3-2x^6";
precise_res = "2x^3+x+2x^7-2x^6";
EXPECT_EQ(addExpression(expr1,expr2),precise_res);

}