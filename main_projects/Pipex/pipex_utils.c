/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:02:37 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/07 14:03:27 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(char *cmd, char **envp)
{
	char	*argv[4];

	argv[0] = "/bin/sh";
	argv[1] = "-c";
	argv[2] = cmd;
	argv[3] = NULL;
	if (execve("/bin/sh", argv, envp) == -1)
	{
		perror("Execve error!");
		exit(EXIT_FAILURE);
	}
}
