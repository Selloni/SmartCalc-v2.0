#include "s21_calc.h"

typename ModelCalc::Data ModelCalc::pull_stack() {
  char buff[256] = {'\0'};
  size_t len = value_.size() + 1;
  size_t j = 0;
  size_t k = 0;
  bool num_flag = 0;
  bool have_trg = 0;
  if (value_[0] == '-' || value_[0] == '+') {
    num_.push(0);
  }
  for (size_t i = 0; i != len; ++i) {
    if ((value_[i] >= '0' && value_[i] <= '9') || value_[i] == '.') {
      buff[j] = value_[i];
      num_flag = 1;
      ++j;
      if (value_[i + 1] == '(')
        symbol_.push('*');
    } else if (value_[i] == 'X') {
      num_.push(x_value_);
      if ((value_[i - 1] >= '0' && value_[i - 1] <= '9') ||
          (value_[i + 1] >= '0' && value_[i + 1] <= '9'))
        num_.push('*');
    } else if (value_[i] == '(' &&
               (value_[i + 1] == '+' || value_[i + 1] == '-')) {
      num_.push(0);
      symbol_.push('(');
    } else {
      j = 0;
      if (num_flag) {
        num_.push(std::stod(buff));
        memset(buff, '\0', sizeof(buff));
      }
      num_flag = 0;
      if (value_[i] >= 'a' && value_[i] <= 'z') { // alphabet
        buff[k] = value_[i];
        k++;
        have_trg = 1;
      } else if (have_trg) {
        trigonometr(buff); ////
        have_trg = 0;
        symbol_.push('(');
        memset(buff, '\0', sizeof(buff));
      } else {
        if (value_[i] != '\0') {
          calc(value_[i]);
        } else
          break;
      }
    }
  }
  return total();
}

int ModelCalc::trigonometr(std::string str) {
  int err = 0;
  // char str[5] = {'\0'};
  std::string tmp0 = "cos";
  std::string tmp1 = "sin";
  std::string tmp2 = "tan";
  std::string tmp3 = "acos";
  std::string tmp4 = "asin";
  std::string tmp5 = "atan";
  std::string tmp6 = "sqrt";
  std::string tmp7 = "ln";
  std::string tmp8 = "log";
  if (str == tmp0) { // cos
    err = 1;
    symbol_.push('B');
  } else if (str == tmp1) { // sin
    err = 1;
    symbol_.push('C');
  } else if (str == tmp2) { // tan
    err = 1;
    symbol_.push('D');
  } else if (str == tmp3) { // acos
    err = 1;
    symbol_.push('E');
  } else if (str == tmp4) { // asin
    err = 1;
    symbol_.push('F');
  } else if (str == tmp5) { // atan
    err = 1;
    symbol_.push('G');
  } else if (str == tmp6) { // sqrt
    err = 1;
    symbol_.push('H');
  } else if (str == tmp7) { // ln
    err = 1;
    symbol_.push('I');
  } else if (str == tmp8) { // log
    err = 1;
    symbol_.push('J');
  }
  return (err);
}

int ModelCalc::calc(char oper) {
  if (!symbol_.empty()) {
    Data var1 = 0;
    Data var2 = 0;
    Data sum = 0;
    if (oper == ')') {
      sum = total();
    } else if ((pars_sing(oper) > pars_sing(symbol_.top())) || oper == '(') {
      symbol_.push(oper);
    } else if (oper == '^' && symbol_.top() == '^') {
      symbol_.push(oper);
    } else {
      while ((!symbol_.empty()) &&
             (pars_sing(oper) <= pars_sing(symbol_.top()))) {
        char stek_oper = pop_char();
        if (stek_oper < 75 && stek_oper > 65) {
          var1 = pop_float();
          sum = calc_triginimetr(var1, stek_oper);
          num_.push(sum);
        } else {
          var1 = pop_float();
          var2 = pop_float();
          if (stek_oper == '+') {
            sum = var2 + var1;
          } else if (stek_oper == '-') {
            sum = var2 - var1;
          } else if (stek_oper == '/') {
            sum = var2 / var1;
          } else if (stek_oper == '*') {
            sum = var2 * var1;
          } else if (stek_oper == '^') {
            sum = pow(var2, var1);
          }
          num_.push(sum);
        }
      }
      symbol_.push(oper);
    }
  } else {
    symbol_.push(oper);
  }
  return 0;
}

typename ModelCalc::Data ModelCalc::total() {
  Data var1 = 0;
  Data var2 = 0;
  Data sum = 0;
  Data total;
  char sign;
  int flag = 0;
  while (!symbol_.empty()) {
    sign = pop_char();
    if (sign == '(') {
      flag = 1;
      break;
    }
    if (sign > 65 && sign < 75) {
      sum = calc_triginimetr(pop_float(), sign);
    } else {
      var1 = pop_float();
      var2 = pop_float();
      if (sign == '+') {
        sum = var2 + var1;
      } else if (sign == '-') {
        sum = var2 - var1;
      } else if (sign == '/') {
        sum = var2 / var1;
      } else if (sign == '*') {
        sum = var2 * var1;
      } else if (sign == '^') {
        sum = pow(var2, var1);
      } else if (sign == '%') {
        sum = fmod(var2, var1);
      }
    }
    num_.push(sum);
  }
  if (flag == 1) {
    total = sum;

  } else {
    total = pop_float();
  }
  return (total);
}

int ModelCalc::pars_sing(char val) {
  int prior = 0;
  if (val == '+') {
    prior = 2;
  } else if (val == '-') {
    prior = 2;
  } else if (val == '/') {
    prior = 3;
  } else if (val == '*') {
    prior = 3;
  } else if (val == '^') {
    prior = 5;
  } else if (val == '(') {
    prior = 1;
  } else if (val == ')') {
    prior = 1;
  } else if (val == '%') {
    prior = 3;
  } else if (val >= 'B' && val <= 'J') {
    prior = 4;
  }
  return prior;
}

typename ModelCalc::Data ModelCalc::calc_triginimetr(Data var, char stek_oper) {
  Data res = 0;
  if (stek_oper == 'B') {
    res = cos(var);
  } else if (stek_oper == 'C') {
    res = sin(var);
  } else if (stek_oper == 'D') {
    res = tan(var);
  } else if (stek_oper == 'E') {
    res = acos(var);
  } else if (stek_oper == 'F') {
    res = asin(var);
  } else if (stek_oper == 'G') {
    res = atan(var);
  } else if (stek_oper == 'H') {
    res = sqrt(var);
  } else if (stek_oper == 'J') {
    res = log(var);
  }
  return res;
}

char ModelCalc::pop_char() {
  char val = symbol_.top();
  // std::cout <<"char:"<<val << "\n";
  symbol_.pop();
  return val;
}

typename ModelCalc::Data ModelCalc::pop_float() {
  Data val = num_.top();
  // std::cout <<"int:"<< val << "\n";
  num_.pop();
  return val;
}

void ModelCalc::set_value(std::string str) { this->value_ = str; }

int ModelCalc::validation(std::string value) {
  int err_flag = 1;
  int num_flag = 1;
  int i = 0;
  int point = 0;
  int len = value.length();
  if (len != 0) {
    if (value[0] == 94 || value[0] == 46 || value[0] == 47 || value[0] == 42 ||
        value[0] == 41 || value[i] == 37) { //  )^./*
      err_flag = 1;
    } else {
      int bracket = 0;
      while (value[i] != '\0') {
        if (((value[i] > 41 && value[i] <= 47) || value[i] == 94 ||
             value[i] == 37) &&
            ((value[i + 1] >= 41 && value[i + 1] <= 47) || value[i + 1] == 94 ||
             value[i + 1] == 37)) { //  )*+,-./^%
          if ((value[i] != ')' && value[i - 1] != ')') ||
              (value[i] != ')' && value[i + 1] != ')'))
            break;
        } else if (value[i] == '(' &&
                   ((value[i + 1] >= 41 && value[i + 1] <= 47) ||
                    value[i + 1] == 94 || value[i + 1] == 37) &&
                   (value[i + 1] != 45 || value[i + 1] != 43)) {
          break;
        } else if (value[i] == '*' || value[i] == '+' || value[i] == '/' ||
                   value[i] == '-') {
          point = 0;
        } else if (value[i] == 46 && point == 0) { // точка
          point++;
          if (point > 1) {
            break;
          }
        } else if (value[i] == '(') {
          bracket++;
        } else if (value[i] == ')') {
          if (bracket > 0) {
            bracket--;
          } else {
            break;
          }
        } else if ((value[i] > 47 && value[i] < 58) || value[i] == 'X') {
          num_flag = 0; //  для защиты от пустых скобок
        }
        i++;
        if (i == len && bracket == 0 && num_flag == 0) {
          if ((value[i - 1] >= '0' && value[i - 1] <= '9') ||
              value[i - 1] == ')' || value[i - 1] == 'X') {
            err_flag = 0;
          }
        }
      }
    }
  }
  return (err_flag); //  0 not error
}