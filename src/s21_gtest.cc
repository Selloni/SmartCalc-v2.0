#include <gtest/gtest.h>
#include "controller/s21_calc.h"

s21::ModelCalc pp;

TEST(test, 1) {
  pp.set_value("3+4*2/(1-5)^2");
  pp.pull_stack();
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

