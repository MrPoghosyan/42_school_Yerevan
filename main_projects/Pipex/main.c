/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/07 13:09:52 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/07 20:22:58 by vapoghos		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pip_m;

	check_argc(argc);
	pip_m.infile = open(argv[1], O_RDONLY);
	if (pip_m.infile < 0)
		return (perror("open infile"), 1);
	pip_m.outfile = open(argv[4], O_CREAT | O_WRONLY
			| O_TRUNC, 0644);
	if (pip_m.outfile < 0)
		return (perror("open outfile"), 1);
	if (pipe(pip_m.fd) == -1)
		return (perror("pipe"), 1);
	child_process(&pip_m, argv[2], envp);
	parent_process(&pip_m, argv[3], envp);
	close(pip_m.fd[0]);
	close(pip_m.fd[1]);
	close(pip_m.infile);
	close(pip_m.outfile);
	waitpid(pip_m.pid1, NULL, 0);
	waitpid(pip_m.pid2, NULL, 0);
	return (0);
}
