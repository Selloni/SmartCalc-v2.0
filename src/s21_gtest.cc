#include <gtest/gtest.h>
#include "controller/s21_calc.h"

TEST(test, 1) {
  s21::ModelCalc pp;
  pp.set_value("3+4*2/(1-5)^2");
  pp.pull_stack();
  EXPECT_EQ(pp.itog_, 3.5);
}

TEST(calc, 2) {
  s21::ModelCalc pp;
  pp.set_value("3+4*2");
  pp.pull_stack();
  EXPECT_EQ(pp.itog_, 11);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
