#include "controller/s21_controller.h"

int main() {
  Controller model;
  model.set_string("2+4");
  model.set_value_X(6.6);
  std::cout << model.code_error() << "\n";
  std::cout << model.get_itog();
}