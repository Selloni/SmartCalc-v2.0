#include "s21_calc.h"

using namespace s21;

// typename ModelCalc::Data string_to_double( const std::string& s )
// {
//   std::istringstream i(s);
//   double x;
//   if (!(i >> x))
//     return 0;
//   return x;
// } 

// void not_digital(char c, ) {
//   size_t k = 0;
//   if (c >= 'a' && c <= 'z') {  // alphabet
//     buff[k] = c;
//     have_trg = 1;
//     k++;
//   } else if (have_trg) {
//     trigonometr(&s_lst, str);
//     have_trg = 0;
//     push(&s_lst, 0, '(', -1);  //  сразу после тригонометрии пушу скобку
//     memset(&str, '\0', 256);  //  зачистить статическую строку
//   } else {
//     if (c != '\0') {  // костыль
//       int prior = pars_sing(c);
//       if (prior != 0) {
//         calc(&list, &s_lst, prior, c);
//       }
//     } else {
//       break;
//     }
//   }
// }



void ModelCalc::pull_stack() {
  char buff[256] = {'\0'};
  size_t len = value_.size() + 1;
  size_t j = 0;
  size_t k = 0;
  bool num_flag = 0;
  bool have_trg = 0;
  if (value_[0] == '-' || value_[0] == '+') {
    num_.push(0);
  }
  for(size_t i = 0; i != len; ++i) {
    if ((value_[i] >= '0' && value_[i] <= '9') || value_[i] == '.' ) {
      buff[j] = value_[i];
      num_flag = 1;
      ++j;
      if (value_[i+1] == '(' || value_[i-1]== ')') symbol_.push('*');
    } else if (value_[i] == 'X') {
      num_.push(x_value_);
      if ((value_[i - 1] >= '0' && value_[i - 1] <= '9') ||
          (value_[i + 1] >= '0' && value_[i + 1] <= '9')) num_.push('*');
    } else if (value_[i] == '(' && (value_[i + 1] == '+' || value_[i + 1] == '-')) {
      num_.push(0);
      symbol_.push('(');
    } else {
      j = 0;
      if(num_flag) {
        num_.push(std::stod(buff));
        memset(buff, '\0', sizeof(buff));
      } 
      num_flag = 0;
      if (value_[i] >= 'a' && value_[i] <= 'z') {  // alphabet
        buff[k] = value_[i];
        k++;
      } else if (have_trg) {
        trigonometr(buff);  //// 
        have_trg = 0;
        symbol_.push('(');
        memset(buff, '\0', sizeof(buff));
      } else {
        if (value_[i] != '\0') {
          calc(value_[i]);
        } else break;
      }
    }
  }
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
  if (str == tmp0) {  // cos
    err = 1;
    symbol_.push('B');
  } else if (str == tmp1) {  // sin
    err = 1;
    symbol_.push('C');
  } else if (str == tmp2) {  // tan
    err = 1;
    symbol_.push('D');
  } else if (str == tmp3) {  // acos
    err = 1;
    symbol_.push('E');
  } else if (str == tmp4) {  // asin
    err = 1;
    symbol_.push('F');
  } else if (str == tmp5) {  // atan
    err = 1;
    symbol_.push('G');
  } else if (str == tmp6) {  // sqrt
    err = 1;
    symbol_.push('H');
  } else if (str == tmp7) {  // ln
    err = 1;
    symbol_.push('I');
  } else if (str == tmp8) {  // log
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
    char stek_oper = symbol_.top();
    if (oper == ')') {
      sum = total();
    } else if (pars_sing(oper) > pars_sing(stek_oper) || oper == '(') {
      // /* если в стеке приоритет меньше чем текущий, кладем знак в стек */
      symbol_.push(oper);
    } else {  //  рекурсия или цикл что бы постоянно проверял условие
      while ((!symbol_.empty()) && pars_sing(oper) <= pars_sing(stek_oper)) {
        stek_oper = symbol_.top();
        symbol_.pop();
        if (stek_oper < 75 && stek_oper > 65) {
          var1 = pop_char();
          sum = calc_triginimetr(var1, stek_oper);
          push(list, sum, '0', 0);
        } else {
          var1 = pop_char();
          var2 = pop_char();
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
          push(list, sum, '0', 0);
        }
      }
      push(s_lst, 0, oper, next_prior);
    }
  } else {
    symbol_.push(oper);
  }
  return 0;
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

char ModelCalc::pop_char() {
  char val = symbol_.top();
  symbol_.pop();
  return val;
}