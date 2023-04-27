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
      }
    }
  }

}