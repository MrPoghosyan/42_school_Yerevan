#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void expand_str(char *str)
{
	int first_word = 1;

	while (is_space(*str))
		str++;
	while (*str)
	{
		if (!is_space(*str))
		{
			write(1, str, 1);
			first_word = 0;
		}
		else if (!first_word)
		{
			while (is_space(*str))
				str++;
			if (*str)
				write(1, "   ", 3);
			continue;
		}
		str++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
