/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:20:17 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/12 11:55:07 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_long(const char *c)
{
	int	count;

	count = 0;
	while (c[count] != '\0')
		count++;
	return (count);
}

void	ft_putstr(const char *c)
{
	write(1, c, ft_long(c));
}

int	ft_open(const char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Cannot read file.\n");
		return (-1);
	}
	return (fd);
}

ssize_t	ft_read(int fd)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read <= 0)
			break ;
		write(1, buffer, bytes_read);
	}
	if (bytes_read < 0)
	{
		ft_putstr("Cannot read file.\n");
		return (1);
	}
	return (0);
}
