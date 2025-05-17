#include "pipex.h"

static char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_line;
	char	*full_path;
	int		i;

	path_line = get_path_line(envp);
	if (!path_line)
		return (NULL);
	paths = ft_split(path_line, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin3((const char *)paths[i],
				(const char *)"/", (const char *)cmd);
		if (!full_path)
			return (free_split(paths), NULL);
		if (access(full_path, X_OK) == 0)
			return (free_split(paths), full_path);
		free(full_path);
		++i;
	}
	return (free_split(paths), NULL);
}

void	exec_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		perror("split");
		exit(1);
	}
	path = find_path(args[0], envp);
	if (!path)
	{
		perror(args[0]);
		free_split(args);
		exit(1);
	}
	execve(path, args, envp);
	perror("execve");
	free_split(args);
	free(path);
	exit(1);
}
