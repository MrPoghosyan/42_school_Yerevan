#include "header.h"

void	exec_command(char *cmd, char **envp)
{
	char	*argv[4];

	argv[0] = "/bin/bash";
	argv[1] = "-c";
	argv[2] = cmd;
	argv[3] = NULL;
	if (execve("/bin/bash", argv, envp) == -1)
	{
		perror("Execve error!");
		exit(EXIT_FAILURE);
	}
}
