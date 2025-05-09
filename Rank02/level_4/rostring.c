#include <stdlib.h>
#include <unistd.h>

int is_seperator(char c)
{
	return (c == ' ' || c == '\t');
}

void	rostring(char *str)
{
	int flag = 0;
	char *end;

	for (;*str != '\0'; str++) {
		while (is_seperator(*str)) ++str;
		end = str -1;
		while (flag && !is_seperator(*str))
			str++;
		while (!is_seperator(*str))
		{
			write(1, str++, 1);
			flag = 1;
		}
		write (1, " ", 1);
	}
	if (flag)
	{
		while (is_seperator(*end))
			write (1, end++, 1);
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rostring(argv[1]);
	write(1, "\n", 1);
	return 0;
}
