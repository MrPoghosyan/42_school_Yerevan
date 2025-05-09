#include <stdio.h>
#include <stdlib.h>

void	do_op(int a, int b, char op)
{
	if (op == '+')
		printf("%d", a + b);
	else if (op == '-')
		printf("%d", a - b);
	else if (op == '*')
		printf("%d", a * b);
	else if (op == '/')
		printf("%d", a / b);
	else if (op == '%')
		printf("%d", a % b);
}

int main(int argc, char **argv)
{
	if (argc == 4)
		do_op(atoi(argv[1]), atoi(argv[3]), argv[2][0]);
	printf("\n");

	return(0);
}
