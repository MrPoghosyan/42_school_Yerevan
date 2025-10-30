#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>

int parse_expr(const char **s);

int parse_factor(const char **s)
{
	if (**s == '(')
	{
		(*s)++;
		int val = parse_expr(s);
		if (val == -1)
			return (-1);
		if (**s != ')')
		{
			printf("Unexpected token '%c'\n", **s ? **s : ' ');
			return (-1);
		}
		(*s)++;
		return (val);
	}
	else if (isdigit(**s))
		return (*(*s)++ - '0');
	else if (**s == '\0')
	{
		printf("Unexpected end of input\n");
		return (-1);
	} else {
		printf ("Unexpected token '%c'\n", **s);
		return (-1);
	}
}

int parse_term(const char **s)
{
	int right;
	int value = parse_factor(s);

	if (value == -1)
		return (-1);
	while (**s == '*')
	{
		(*s)++;
		right = parse_factor(s);
		if (right == -1)
			return (-1);
		value *= right;
	}
	return (value);
}

int parse_expr(const char **s)
{
	int right;
	int value = parse_term(s);

	while (**s == '+')
	{
		(*s)++;
		right = parse_term(s);
		if (right == -1)
			return (-1);
		value += right;
	}
	return (value);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	const char *s = argv[1];
	int result = parse_expr(&s);

	if (result == -1)
		return (1);

	if (*s)
	{
		printf("Unexpected token '%c'\n", *s);
		return (1);
	}
	else
		printf("%d\n", result);

	return (0);
}
