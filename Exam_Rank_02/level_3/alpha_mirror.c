#include <unistd.h>

void	alpha_mirror(char *str){
	int i = 0;
	char c;

	while (str[i])
	{
		c = str[i];
		if (c >= 'a' && c <= 'z')
			c = 'z' - (c - 'a');
		else if (c >= 'A' && c <= 'Z')
			c = 'Z' - (c - 'A');
		write (1, &c, 1);
		++i;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);

	write(1, "\n", 1);

	return (0);
}
