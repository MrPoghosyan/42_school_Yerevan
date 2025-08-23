#include "header.h"

static char	*print_prompt(void)
{
	const char	*prompt = "\033[1;35m┌──[\033[1;36mMyBash\033[1;35m]"
		"\n└─\033[1;32m$ \033[0m";
	char		*line;

	line = readline(prompt);
	if (!line)
	{
		printf("exit\n");
		return (NULL);
	}
	if (*line)
		add_history(line);
	return (line);
}

static int	fork_proces(char *line, char **envp)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(line);
		return (1);
	}
	else if (pid == 0)
		exec_command(line, envp);
	else
		waitpid(pid, &status, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	if (argc != 1)
		return (1);
	while (1)
	{
		line = print_prompt();
		if (!line)
			break ;
		if (fork_proces(line, envp) == 1)
			continue ;
		free(line);
	}
	rl_clear_history();
	return (0);
}
//int fd = open(stdout_filename, O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
