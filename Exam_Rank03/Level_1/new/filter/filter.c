#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *read_out(void)
{
	int i = 0;
	char *str = (char *)malloc(100000);
	if (!str)
		return (NULL);
	while(read(0, &str[i], 1) > 0)
		i++;
	str[i] = '\0';

	return (str);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		size_t i, j;
		size_t len = strlen(argv[1]);
		char *str = read_out();
		if (!str)
			return (1);
		char *str_tmp = str;

		while (*str)
		{
			i = 0;
			while (i < len)
			{
				if (str[i] != argv[1][i])
					break ;
				i++;
			}
			if (i == len)
			{
				j = 0;
				while (j++ < len)
					write(1, "*", 1);
				str += len;
			}
			else
				write (1, str++, 1);
		}
		free(str_tmp);

	}
	else
		return (1);
	return (0);
}
