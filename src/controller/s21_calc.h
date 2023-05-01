#pragma once
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>

namespace s21{
  class ModelCalc {
    public:
    using Data = double;
    std::stack<Data> num_;
    std::stack<char> symbol_;
    std::string value_ = {'\0'};
    Data itog_ = 0.0;
    Data x_value_ = 0.0;
    public:
    // void push(Node **plist, Data value, char oper, int prior);
    // int is_emty(Node **list);
    // Data pop(Node **plist);
    // char pop_s(Node **plist);
    // Data string_to_double( const std::string& s);
    void set_value(std::string str);
    void pull_stack();
    int trigonometr(std::string str);
    // int validation(char *value);
    int pars_sing(char val);
    int calc(char oper);
    // void print(Node *list);
    Data total();
    Data calc_triginimetr(Data var, char stek_oper);
    char pop_char();
    Data pop_float();
  };  // ModelCalc
}