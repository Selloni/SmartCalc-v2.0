#include <gtest/gtest.h>
#include "controller/s21_calc.h"


ModelCalc pp;

TEST(test, 1) {
  // ModelCalc pp;
  pp.set_value("3+4*2/(1-5)^2");
  EXPECT_EQ(pp.pull_stack(), 3.5);
}

TEST(calc, 2) {
  // ModelCalc pp;
  pp.set_value("3+4*2");
  EXPECT_EQ(pp.pull_stack(), 11);
}

// TEST(trgn, 3) {
//   pp.set_value("(132+sin(asin(sqrt(ln(log(228.11)))))-4*5^6*(123))");
//   EXPECT_EQ(pp.pull_stack(), -7687367.073);
// }

TEST(x, 4) {
  pp.x_value_=3;
  pp.set_value("4((-3+X)2)");
  EXPECT_EQ(pp.pull_stack(), -8);
}

TEST(T, 5) {
  pp.set_value("2^2^3");
  EXPECT_EQ(pp.pull_stack(), 264);
}

TEST(mod, 6) {
  pp.set_value("5%3");
  EXPECT_EQ(pp.pull_stack(), 2);
}

// TEST(trgn, 7) {
//   pp.set_value("(132+sin(asin(sqrt(ln(log(228.11)))))-4*5^6*(123))");
//   EXPECT_EQ(pp.pull_stack(), -7687367.073);
// }

TEST(trgn, 8) {
  pp.set_value("sin(2)");
  EXPECT_EQ(pp.pull_stack(), 0.909);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
