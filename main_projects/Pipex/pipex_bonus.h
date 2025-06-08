/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:11:53 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/07 15:08:50 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "./Libft/libft.h"
# include "./get_next_line.h"
# include "./pipex.h"

# define READ_END 0
# define WRITE_END 1

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		pipe_fd[2];
	int		here_doc;
	char	*limiter;
	pid_t	pid;
	char	**paths;
	char	**cmd_args;
}	t_pipex;

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
void	exec_cmd(t_pipex *pipex, char *cmd, char **envp);
void	pipe_handler(t_pipex *pipex, int argc, char **argv, char **envp);
void	here_doc(t_pipex *pipex);
void	error_exit(char *msg, int exit_code);
void	clean_exit(t_pipex *pipex, char *msg, int exit_code);
void	close_fds(t_pipex *pipex);
char	*get_cmd_path(char *cmd, char **paths);

#endif
