#include <unistd.h>

int ft_strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

void ft_swap(char *a, char *b)
{
	char tmp = *a;

	*a = *b;
	*b = tmp;
}

void generate_permutations(char *str, int start, int end)
{
	if (start == end)
	{
		write(1, str, end +1);
		write(1, "\n", 1);
	}
	else
	{
		for (int i = start; i <= end; ++i)
		{
			ft_swap(&str[start], &str[i]);
			generate_permutations(str, start +1, end);
			ft_swap(&str[start], &str[i]); //Backtrack
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	char *input = argv[1];
	int len = ft_strlen(input);
	generate_permutations(input, 0, len -1);

	return (0);
}
