#include <unistd.h>

int has_more_words(char *str)
{
	while (*str){
		if (*str != ' ' && *str != '\t')
			return (1);
		str++;
	}
	return (0);
}

void epur_str(char *str)
{
	int word_started = 0;

	while (*str == ' ' || *str == '\t')
		str++;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
		{
			if (word_started && has_more_words(str))
			{
				write(1, " ", 1);
				word_started = 0;
			}
		}
		else
		{
			write(1, str, 1);
			word_started = 1;
		}
		str++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);

	write(1, "\n", 1);

	return (0);
}
