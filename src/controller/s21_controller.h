#pragma once
#include "../model/s21_calc.h"

class Controller {
  ModelCalc model_;

public:
  void set_string(std::string str);
  void set_value_X(ModelCalc::Data x);
  ModelCalc::Data get_itog();
  int code_error();
}; // controller
