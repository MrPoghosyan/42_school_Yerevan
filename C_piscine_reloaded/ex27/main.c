/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:21:47 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/12 11:43:06 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 1)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	fd = ft_open(av[1]);
	if (fd != -1)
	{
		if (ft_read(fd) != 0)
		{
			close(fd);
			return (1);
		}
		close(fd);
	}
	return (0);
}
