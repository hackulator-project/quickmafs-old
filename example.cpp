#include <stdio.h>
#include "quickmafs.h"
int main() {
	const char *question = "2+2-1";
	printf("Question: %s, Answer: %f", question, evaluate(question));
	return 0;
}
