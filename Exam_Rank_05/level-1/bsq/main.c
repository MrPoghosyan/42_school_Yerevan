#include "bsq.h"

static int	process_file(char *path)
{
	FILE	*fp;
	int		ret;

	fp = fopen(path, "r");
	if (!fp)
	{
		fputs("map error\n", stderr);
		return (1);
	}
	ret = process_stream(fp);
	fclose(fp);
	return (ret);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		process_stream(stdin);
	else
	{
		i = 1;
		while (i < argc)
		{
			process_file(argv[i]);
			i++;
		}
	}
	return (0);
}
