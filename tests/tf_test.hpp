#ifndef __TF_TEST_HPP__
#define __TF_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/type.hpp"
#include "../header/tf.hpp"

using namespace std;

TEST(TFTest, DisplayTest1) {
    Type* type = new TF();
    GameQuestion* g = new Quesiton("The lead singer of The Neighbourhood is Cole Sprouse.", False);
    stringstream s;
    type->Display(g, s);
    EXPECT_EQ(s.str(), "\tThe lead singer of The Neighbourhood is Cole Sprouse.\n");
}

TEST(TFTest, DisplayTest2) {
    Type* type = new TF();
    GameQuestion* g = new Quesiton("Dolly Parton is Miley Cyrus’s God Mother.", True);
    stringstream s;
    type->Display(g, s);
    EXPECT_EQ(s.str(), "\tDolly Parton is Miley Cyrus’s God Mother.\n");
}

TEST(TFTest, DisplayTest3) {
    Type* type = new TF();
    GameQuestion* g = new Quesiton("Electrons are larger than molecules.", False);
    stringstream s;
    type->Display(g, s);
    EXPECT_EQ(s.str(), "\tElectrons are larger than molecules.\n");
}

TEST(TFTest, DisplayTest4) {
    Type* type = new TF();
    GameQuestion* g = new Quesiton("The San Francisco 49ers have won 5 NFL championships?", False);
    stringstream s;
    type->Display(g, s);
    EXPECT_EQ(s.str(), "\tThe San Francisco 49ers have won 5 NFL championships?\n");
}
#endif
