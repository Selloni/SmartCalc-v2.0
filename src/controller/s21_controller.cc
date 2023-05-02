#include "s21_controller.h"

void Controller::set_string(std::string str) {
  this->model_->value_ = str;
}

void Controller::set_value_X(ModelCalc::Data x){
  this->model_->x_value_ = x;
}

void Controller::set_itog(ModelCalc::Data total) {

}