#include <math.h>
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
  double result = get() - '0';
  while (peek() >= '0' && peek() <= '9') {
    result = 10*result + get() - '0';
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
      result = pow (result, factor());
    if(get() == 'r')
      result = pow (factor(), 1/result); // 3r27 becomes 27 to the power of 1/3
      return result;

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

double trig() //trig functions sin, cos, tan
{
  double result = term();
  while (peek() == "sin" || peek() == "cos" || peek() = "tan")
    if (get() == "sin")
double log()
{
  double result = exponent();
  if (peek() == "log")
    result = log (result, exponent());
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
