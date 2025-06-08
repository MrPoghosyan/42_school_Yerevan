/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:10:58 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/07 13:11:02 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Required headers
# include <fcntl.h> //open.
//close, read, write, access, dup, dup2, execve, fork, pipe, exit, unlink.
# include <unistd.h> 
# include <stdlib.h> //malloc, free, exit.
# include <stdio.h> //perror.
# include <string.h> //strerror.
# include <sys/wait.h> //wait, waitpid.
# include <errno.h> //for errno = Einval;

# include "./Libft/libft.h"

typedef struct s_pipe
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipe;

// Function declarations
void	child_process(t_pipe *pip_m, char *cmd1, char **envp);
void	parent_process(t_pipe *pip_m, char *cmd2, char **envp);
void	exec_command(char *cmd, char **envp);

//utils functions
int		empty_argument(const char *str);
void	check_argc(int argc);
void	free_split(char **line);
char	*get_path_line(char **envp);
char	*ft_strjoin3(const char *s1, const char *s2, const char *s3);

#endif
