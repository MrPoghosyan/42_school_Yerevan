#include "pipex.h"

static void	close_fd(int file, int fd[2], const char *str)
{
	perror(str);
	close(fd[0]);
	close(fd[1]);
	close(file);
	exit (1);
}

void	child_process(int infile, int fd[2], char *cmd1, char **envp)
{
	if (empty_argument(cmd1))
	{
		errno = EINVAL;
		perror("cmd1");
		exit(1);
	}
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		close_fd(infile, fd, "dup2 infile");
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close_fd(infile, fd, "dup2 pipe write");
	}
	close(fd[0]);
	close(fd[1]);
	close(infile);
	exec_command(cmd1, envp);
}

void	parent_process(int outfile, int fd[2], char *cmd2, char **envp)
{
	wait(NULL);
	if (empty_argument(cmd2))
	{
		errno = EINVAL;
		perror("cmd2");
		exit(1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close_fd(outfile, fd, "dup2 pipe read");
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		close_fd(outfile, fd, "dup2 outfile");
	}
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	exec_command(cmd2, envp);
}
