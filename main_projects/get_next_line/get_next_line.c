/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:31:48 by vapoghos          #+#    #+#             */
/*   Updated: 2025/02/06 13:30:00 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, buffer, 0) < 0))
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
	}
	if (!remainder || !*remainder)
		return (NULL);
	line = extract_line(remainder);
	remainder = save_remainder(remainder);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("get_next_line.h", O_RDONLY);
	if (fd == -1)
	{
		printf("Dont open file!");
		return 1;
	}

	char *r_file = get_next_line(fd);
	if (!r_file)
	{
		printf("Dont read file!");
		return 2;
	}
	printf("file: %s\n", r_file);

	for (int i = 0; i < 10; ++i)
		printf("cikl: %s\n", get_next_line(fd));

	close(fd);
	return 0;
}
*/
