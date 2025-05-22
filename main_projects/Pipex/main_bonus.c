#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		infile;
	int		cmd_start;
	int		outfile;
	pid_t	pid;

	check_argc_bonus(argc, argv);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		infile = here_doc(argv[2]);
		outfile = open(argv[argc-1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		cmd_start = 3;
	}
	else
	{
		infile = open(argv[1], O_RDONLY);
		if (infile < 0)
			return (perror("open infile"), 1);
		outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		cmd_start = 2
	}
	return (0);
}
