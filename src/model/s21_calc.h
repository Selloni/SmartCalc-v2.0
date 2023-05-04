#pragma once
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class ModelCalc {
public:
  using Data = double;
  std::stack<Data> num_;
  std::stack<char> symbol_;
  std::string value_ = {'\0'};
  Data x_value_ = 0.0;
  // Data total_ = 0.0;
public:
  void set_value(std::string str);
  Data pull_stack();
  int trigonometr(std::string str);
  // int validation(char *value);
  int pars_sing(char val);
  int calc(char oper);
  Data total();
  Data calc_triginimetr(Data var, char stek_oper);
  char pop_char();
  Data pop_float();
  int validation(std::string value);

}; // ModelCalc
