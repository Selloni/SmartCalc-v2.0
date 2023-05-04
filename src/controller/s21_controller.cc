#include "s21_controller.h"

void Controller::set_string(std::string str) { this->model_.value_ = str; }

void Controller::set_value_X(ModelCalc::Data x) { this->model_.x_value_ = x; }

typename ModelCalc::Data Controller::get_itog() {
  return this->model_.pull_stack();
}

int Controller::code_error() { return this->model_.validation(model_.value_); }
