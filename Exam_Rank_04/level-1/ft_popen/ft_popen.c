#include <unistd.h>		// pipe, fork, dup2, execvp, close
#include <stdlib.h>		// exit
#include <sys/types.h>	// pid_t


static void	close_fd_error(int *fd)
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	fd[0] = fd[1] = -1;
	exit(1);
}

static void child_proces(const char *file, char *const argv[], char type, int *fd)
{
	if (type == 'w')
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			close_fd_error(fd);
	}
	else if (type == 'r')
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			close_fd_error(fd);
	}
	close(fd[1]);
	close(fd[0]);
	execvp(file, argv);
	exit(1);
}

static int parent_proces(char type, int *fd)
{
	if (type == 'r')
	{
		close(fd[1]);
		fd[1] = -1;
		return (fd[0]);
	}
	else if (type == 'w')
	{
		close(fd[0]);
		fd[0] = -1;
		return (fd[1]);
	}
	return (-1);
}

int ft_popen(const char *file, char *const argv[], char type)
{
	int fd[2];
	pid_t cpid;

	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	if (pipe(fd) == -1)
		return (-1);

	cpid = fork();
	if (cpid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (cpid == 0)
			child_proces(file, argv, type, fd);
	return (parent_proces(type, fd));
}
/*
#include <stdio.h>

char *get_next_line(int fd);

int main()
{
	int fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	dup2(fd, 0);
	fd = ft_popen("grep", (char *const []){"grep", "c", NULL}, 'r');
	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line); 
		free(line);
	}
	close(fd);
}
*/
