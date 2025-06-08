/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:11:24 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/07 18:07:31 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	clean_exit(t_pipex *pipex, char *msg, int exit_code)
{
	if (msg)
		error_exit(msg, exit_code);
	free_split(pipex->paths);
	close_fds(pipex);
	exit(exit_code);
}

void	init_paths(t_pipex *pipex, char **envp)
{
	int		i;
	char	*path_line;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
	{
		pipex->paths = NULL;
		return ;
	}
	path_line = envp[i] + 5;
	pipex->paths = ft_split(path_line, ':');
}

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->here_doc = 0;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (argc < 6)
			error_exit("Invalid number of arguments", 1);
		pipex->here_doc = 1;
		pipex->limiter = argv[2];
		here_doc(pipex);
		pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT
				| O_APPEND, 0644);
	}
	else
	{
		pipex->in_fd = open(argv[1], O_RDONLY | O_CLOEXEC);
		if (pipex->in_fd < 0)
			error_exit("Input file error", 1);
		pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT
				| O_TRUNC, 0644);
	}
	if (pipex->out_fd < 0)
		error_exit("Output file error", 1);
	init_paths(pipex, envp);
}

void	exec_cmd(t_pipex *pipex, char *cmd, char **envp)
{
	char	*path;
	char	**args;

	if (!ft_strchr(cmd, '\'') && !ft_strchr(cmd, '\"'))
	{
		args = ft_split(cmd, ' ');
		if (!args)
			clean_exit(pipex, "Command split error", 1);
		path = get_cmd_path(args[0], pipex->paths);
		if (!path)
		{
			ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
			ft_putendl_fd(args[0], STDERR_FILENO);
			free_split(args);
			clean_exit(pipex, NULL, 127);
		}
		close_fds(pipex);
		execve(path, args, envp);
		free(path);
		free_split(args);
		clean_exit(pipex, "Execve error", 1);
	}
	else
		exec_command(cmd, envp);
}

void	pipe_handler(t_pipex *pipex, int argc,
char **argv, char **envp)
{
	int	i;

	i = 2 + pipex->here_doc;
	while (i < argc - 2)
	{
		if (pipe(pipex->pipe_fd) < 0)
			error_exit("Pipe error", 1);
		pipex->pid = fork();
		if (pipex->pid < 0)
			error_exit("Fork error", 1);
		if (pipex->pid == 0)
		{
			close(pipex->pipe_fd[READ_END]);
			dup2(pipex->in_fd, STDIN_FILENO);
			dup2(pipex->pipe_fd[WRITE_END], STDOUT_FILENO);
			exec_cmd(pipex, argv[i], envp);
		}
		else
		{
			close(pipex->pipe_fd[WRITE_END]);
			close(pipex->in_fd);
			pipex->in_fd = pipex->pipe_fd[READ_END];
			i++;
		}
	}
}
