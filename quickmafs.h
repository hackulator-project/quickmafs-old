#ifndef __QUICKMAFS_H__
#define __QUICKMAFS_H__
char *outtext;
char peek()
{
	return *outtext;
}

char get()
{
	return *outtext++;
}

double expression();

double number()
{
	double result = get() - '0';
	while (peek() >= '0' && peek() <= '9')
	{
		result = 10*result + get() - '0';
	}
	return result;
}

double factor()
{
	if (peek() >= '0' && peek() <= '9')
		return number();
	else if (peek() == '(')
	{
		get(); // '('
		double result = expression();
		get(); // ')'
		return result;
	}
	else if (peek() == '-')
	{
		get();
		return -factor();
	}
	return 0; // error
}

double term()
{
	double result = factor();
	while (peek() == '*' || peek() == '/' || peek() == 'a')
		if (get() == '*')
			result *= factor();
		else
			result /= factor();
	return result;
}

double expression()
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
	outtext = (char*)expr;
	double result = expression();
	return result;
}
#endif /*__QUICKMAFS_H__*/
