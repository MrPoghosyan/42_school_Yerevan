/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipex.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/07 13:10:22 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/07 21:05:45 by vapoghos		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

static void	close_fd_error(int file, int fd, const char *str)
{
	if (fd != -1)
		close(fd);
	if (file != -1)
		close(file);
	perror(str);
	exit(1);
}

void	child_process(t_pipe *pip_m, char *cmd1, char **envp)
{
	pip_m->pid1 = fork();
	if (pip_m->pid1 == -1)
		close_fd_error(pip_m->infile, pip_m->fd[1], "Error fork pid1");
	if (pip_m->pid1 == 0)
	{
		if (empty_argument(cmd1))
		{
			errno = EINVAL;
			close_fd_error(pip_m->infile, pip_m->fd[1], "cmd1");
		}
		close(pip_m->fd[0]);
		if (dup2(pip_m->infile, STDIN_FILENO) == -1)
			close_fd_error(pip_m->infile, pip_m->fd[1], "dup2 infile");
		if (dup2(pip_m->fd[1], STDOUT_FILENO) == -1)
			close_fd_error(pip_m->infile, pip_m->fd[1], "dup2 pipe write");
		close(pip_m->fd[1]);
		close(pip_m->infile);
		exec_command(cmd1, envp);
	}
}

void	parent_process(t_pipe *pip_m, char *cmd2, char **envp)
{
	pip_m->pid2 = fork();
	if (pip_m->pid2 == -1)
		close_fd_error(pip_m->outfile, pip_m->fd[0], "Error fork pid2");
	if (pip_m->pid2 == 0)
	{
		if (empty_argument(cmd2))
		{
			errno = EINVAL;
			close_fd_error(pip_m->outfile, pip_m->fd[0], "cmd2");
		}
		close(pip_m->fd[1]);
		if (dup2(pip_m->fd[0], STDIN_FILENO) == -1)
			close_fd_error(pip_m->outfile, pip_m->fd[0], "dup2 pipe read");
		if (dup2(pip_m->outfile, STDOUT_FILENO) == -1)
			close_fd_error(pip_m->outfile, pip_m->fd[0], "dup2 outfile");
		close(pip_m->fd[0]);
		close(pip_m->outfile);
		exec_command(cmd2, envp);
	}
}
