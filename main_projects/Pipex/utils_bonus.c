#include "pipex_bonus.h"

void	check_argc_bonus(int argc, char **argv)
{
	if (argc < 5)
	{
		write(2, "Error: Wrong number of arguments!\n", 34);
		exit(1);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (argc < 7)
		{
			write(2, "Irrelevant arguments!\n", 22);
			exit(1);
		}
	}
}
