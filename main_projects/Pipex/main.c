#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid;

	check_argc(argc);
	infile = open(argv[1], O_RDONLY | O_CLOEXEC);
	if (infile < 0)
		return (perror("open infile"), 1);
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		return (perror("open outfile"), 1);
	if (pipe(fd) == -1)
		return (perror("pipe"), 1);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
		child_process(infile, fd, argv[2], envp);
	else
		parent_process(outfile, fd, argv[3], envp);
	return (0);
}
