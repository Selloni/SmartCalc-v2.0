#include "controller/s21_calc.cc"

int main() {
  using namespace std;
  ModelCalc pp;
  pp.value_ = "2+3";
  pp.pull_stack();
  cout << pp.itog_ ;

}