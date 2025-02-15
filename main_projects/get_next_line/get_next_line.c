/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:31:48 by vapoghos          #+#    #+#             */
/*   Updated: 2025/02/11 14:46:58 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_lin(NULL, buffer);
	if (line == NULL)
		return (NULL);
	line = read_line(fd, buffer, line);
	clean_line(buffer);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("get_next_line.h", O_RDONLY);
    if (fd == -1)
    {
        perror("Ошибка открытия файла");
        return 1;
    }

    char *line = get_next_line(fd);
    if (line)
    {
        printf("Прочитано: %s\n", line);
        free(line);
    }
    else
    {
        printf("Ошибка чтения или файл пуст\n");
    }
    for (int i = 0; i < 10; ++i){
        line = get_next_line(fd);
        printf("✓✅:%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
*/
