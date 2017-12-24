#include<math.h>
#include "quickmafs.h"
char *quickmafs_buffer;
char peek() {
  return *quickmafs_buffer;
}

char get() {
  return *quickmafs_buffer++;
}

double expression();

double number() {
  double result = get() - '0'; //convert to number
  while (peek() >= '0' && peek() <= '9') { //is it a number
    result = 10*result + get() - '0'; //convert to number and put to end
  }
  return result;
}

double factor() { //P
  if (peek() >= '0' && peek() <= '9') {
    return number();
  }
  else if (peek() == '(') {
    get(); // '('
    double result = expression();
    get(); // ')'
    return result;
  }
  else if (peek() == '-') {
    get();
    return -factor();
  }
  return 0; // error
}
double exponent() { //E
  double result = factor();
  while(peek() == '^' || peek() == 'r') {
    if(get() == '^')
      result = pow(result, factor());
    if(get() == 'r')
      result = pow(factor(), 1/result); // 3r27 becomes 27 to the power of 1/3

  }
}
double term() //MD
{
  double result = exponent();
  while (peek() == '*' || peek() == '/' || peek() == 'a')
    if (get() == '*')
      result *= exponent();
    else
      result /= exponent();
  return result;
}

double expression() //AS
{
  double result = term();
  while (peek() == '+' || peek() == '-')
    if (get() == '+')
      result += term();
    else
      result -= term();
  return result;
}
double evaluate(const char *expr) {
  quickmafs_buffer = (char*)expr;
  double result = expression();
  return result;
}
