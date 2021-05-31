#ifndef __FILL_TEST_HPP__
#define __FILL_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/game_question.hpp"
#include "../header/type.hpp"
#include "../header/fill.hpp"

TEST(FillTest, DisplayQ) {
	Type* type = new Fill();
	GameQuestion* g = new Question("How big is the sun?", 5);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tHow big is the sun?\n");
}

#endif // __FILL_TEST_HPP__
