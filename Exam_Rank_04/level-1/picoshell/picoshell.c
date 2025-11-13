#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

void	close_fds(int *fd)
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	fd[0] = fd[1] = -1;
}

void	child_proces(char **cmd, int prev_fd, int *pipefd, int has_next)
{
	if (prev_fd != -1)
	{
		if (dup2(prev_fd, STDIN_FILENO) == -1)
		{
			close_fds(pipefd);
			exit(1);
		}
		close(prev_fd);
	}
	if (has_next)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		{
			close_fds(pipefd);
			exit(1);
		}
		close(pipefd[1]);
	}
	close_fds(pipefd);
	execvp(cmd[0], cmd);
	exit(1);
}

int	parent_proces(int *pipefd, int prev_fd, int has_next)
{
	if (prev_fd != -1)
		close(prev_fd);
	if (has_next)
	{
		close(pipefd[1]);
		return (pipefd[0]);
	}
	return (-1);
}

int	picoshell(char **cmds[])
{
	pid_t	pid;
	int		pipefd[2];
	int		prev_fd = -1;
	int		has_next;
	int		i = 0;

	if (!cmds)
		return (1);
	while (cmds[i])
	{
		has_next = (cmds[i +1] != NULL);
		if (has_next && pipe(pipefd) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
		{
			if (has_next)
				close_fds(pipefd);
			return (1);
		}
		if (pid == 0)
			child_proces(cmds[i], prev_fd, pipefd, has_next);
		prev_fd = parent_proces(pipefd, prev_fd, has_next);
		++i;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
