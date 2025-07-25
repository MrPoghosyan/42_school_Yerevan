/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:17:44 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/07 15:25:34 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(char *msg, int exit_code)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(exit_code);
}

void	close_fds(t_pipex *pipex)
{
	if (pipex->in_fd > 0)
		close(pipex->in_fd);
	if (pipex->out_fd > 0)
		close(pipex->out_fd);
	if (pipex->pipe_fd[READ_END] > 0)
		close(pipex->pipe_fd[READ_END]);
	if (pipex->pipe_fd[WRITE_END] > 0)
		close(pipex->pipe_fd[WRITE_END]);
}

void	here_doc(t_pipex *pipex)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) < 0)
		clean_exit(pipex, "Pipe error", 1);
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line || (ft_strlen(line) == ft_strlen(pipex->limiter)
				+ 1 && !ft_strncmp(line, pipex->limiter,
					ft_strlen(pipex->limiter))))
		{
			free(line);
			break ;
		}
		write(fd[WRITE_END], line, ft_strlen(line));
		free(line);
	}
	close(fd[WRITE_END]);
	pipex->in_fd = fd[READ_END];
}

char	*get_cmd_path(char *cmd, char **paths)
{
	char	*full_path;
	char	*tmp;
	int		i;

	if (!cmd || !*cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = -1;
	while (paths && paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (NULL);
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	return (NULL);
}
