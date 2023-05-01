#include "controller/s21_calc.h"

int main() {
  s21::ModelCalc pp;
  pp.set_value("3+4*2");
  pp.pull_stack();
  // EXPECT_EQ(pp.itog_, 3.5);
  std::cout << pp.itog_ ;
}