#include "pipex.h"

void	child_process(int infile, int fd[2], char *cmd1, char **envp)
{
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("dup2 infile");
		close(fd[0]);
		close(fd[1]);
		close(infile);
		exit (1);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		close(fd[0]);
		close(fd[1]);
		close(infile);
		exit (1);
	}
	close(fd[0]);
	close(fd[1]);
	close(infile);
	exec_command(cmd1, envp);
}

void	parent_process(int outfile, int fd[2], char *cmd2, char **envp)
{
	wait(NULL);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		close(fd[0]);
		close(fd[1]);
		close(outfile);
		exit(1);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile");
		close(fd[0]);
		close(fd[1]);
		close(outfile);
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	exec_command(cmd2, envp);
}
