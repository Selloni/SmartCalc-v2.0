#pragma once
#include "../model/s21_calc.h"

class Controller {
  ModelCalc *model_;
  public:
  void set_string(std::string str);
  void set_value_X(ModelCalc::Data x);
  void set_itog(ModelCalc::Data total);
}; // controller