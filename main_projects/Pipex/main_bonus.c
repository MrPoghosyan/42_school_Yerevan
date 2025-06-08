/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:47:53 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/07 20:20:19 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		error_exit("Usage: ./pipex <infile> <cmd1> <cmd2> ... <outfile>\n"
			"Or: ./pipex here_doc <LIMITER> <cmd1> <cmd2> ... <outfile>", 1);
	ft_memset(&pipex, 0, sizeof(t_pipex));
	init_pipex(&pipex, argc, argv, envp);
	pipe_handler(&pipex, argc, argv, envp);
	pipex.pid = fork();
	if (pipex.pid < 0)
		clean_exit(&pipex, "Fork error", 1);
	if (pipex.pid == 0)
	{
		dup2(pipex.in_fd, STDIN_FILENO);
		dup2(pipex.out_fd, STDOUT_FILENO);
		exec_cmd(&pipex, argv[argc - 2], envp);
	}
	close_fds(&pipex);
	while (wait(NULL) != -1)
		;
	clean_exit(&pipex, NULL, 0);
	free_split(pipex.paths);
	return (0);
}
