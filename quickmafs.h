#ifndef __QUICKMAFS_H__
#define __QUICKMAFS_H__
char *outtext;
char peek();
char get();
double expression();

double number();
double factor();
double term();
double evaluate(const char *expr);
#endif /*__QUICKMAFS_H__*/
