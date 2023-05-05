#include <gtest/gtest.h>
#include "../model/s21_calc.h"


ModelCalc pp;

TEST(test, 1) {
  pp.set_value("3+4*2/(1-5)^2");
  EXPECT_EQ(pp.pull_stack(), 3.5);
}

TEST(calc, 2) {
  pp.set_value("3+4*2");
  EXPECT_EQ(pp.pull_stack(), 11);
}

TEST(trgn, 3) {
  pp.set_value("(132+sin(asin(sqrt(ln(log(228.11)))))/122");
  ASSERT_FLOAT_EQ(pp.pull_stack(), 132.00772);
}

TEST(x, 4) {
  pp.x_value_=2;
  pp.set_value("4((-3+X)2)");
  EXPECT_EQ(pp.pull_stack(), -8);
}

TEST(TT, 5) {
  pp.set_value("2^2^3");
  EXPECT_EQ(pp.pull_stack(), 256);
}

TEST(mod, 6) {
  pp.set_value("5%3");
  EXPECT_EQ(pp.pull_stack(), 2);
}

TEST(trgn, 7) {
  pp.set_value("(132+sin(asin(sqrt(ln(log(228.11)))))-4*5^6*(123))");
  ASSERT_FLOAT_EQ(pp.pull_stack(), -7687367.073);
}

TEST(trgn, 8) {
  pp.set_value("sin(2)");
  ASSERT_FLOAT_EQ(pp.pull_stack(), 0.90929741);
}

TEST(minus, 9) {
  pp.x_value_=2;
  pp.set_value("(-3)^2");
  EXPECT_EQ(pp.pull_stack(), 9);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
