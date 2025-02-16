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

#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
    static char buffer[FD_NUMBER][BUFFER_SIZE + 1];
    char        *line;

    printf("[✓✅ get_next_line: fd=%d, текущий буфер:\n%s\n]", fd, buffer[fd]);

    if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, buffer[fd], 0) < 0))
        return (NULL);

    line = get_lin(NULL, buffer[fd]);  
    if (!line)
        return (NULL);

    line = read_line(fd, buffer[fd], line);
    if (!line) 
        return (NULL);

    printf("[Перед clean_line: буфер=%s]\n", buffer[fd]);
    clean_line(buffer[fd]);
    printf("[После clean_line: буфер=%s]\n", buffer[fd]);

    return (line);
}

/*
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_NUMBER][BUFFER_SIZE + 1];
	char		*line;
	printf("[✓✅get_next_line: fd=%d, current buffer:\n%s\n]", fd, buffer[fd]);

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, buffer[fd], 0) < 0))
		return (NULL);

	printf("[Նախկինում get_line_b: fd=%d, buffer=%s\n]", fd, buffer[fd]);
	line = get_lin(NULL, buffer[fd]);
	printf("[Նարկա get_line_b: fd=%d, buffer=%s\n]", fd, buffer[fd]);
	if (!line)
		return (NULL);

	printf("[Նախկինում read_line_b: fd=%d, buffer=%s, line=%s\n]", fd, buffer[fd], line);
	line = read_line(fd, buffer[fd], line);
	printf("[Ներկա read_line_b: fd=%d, buffer=%s, line=%s\n]", fd, buffer[fd], line);

	if (buffer[fd][0] == '\0') {
    printf("[Զգուշացում. փորձում է մաքրել դատարկ բուֆերը!\n]");
	}
	if (!line)
		return (NULL);
	printf("[Նախկինում clean_line_b: buffer=%s\n]", buffer[fd]);
	clean_line(buffer[fd]);
	printf("[Ներկա clean_line_b: buffer=%s\n]", buffer[fd]);
	return (line);
}*/
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
