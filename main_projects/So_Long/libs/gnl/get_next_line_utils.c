/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:33:42 by vapoghos          #+#    #+#             */
/*   Updated: 2025/02/19 18:29:52 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen_m(const char *str)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

static char	*ft_strchr_m(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*get_line_m(char *line, char *buffer)
{
	char	*result;
	char	*cop_result;
	char	*temp;
	size_t	len;

	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	result = (char *)malloc(ft_strlen_m(line) + (len + 1));
	if (!result)
		return (free(line), NULL);
	cop_result = result;
	temp = line;
	if (temp)
		while (*temp)
			*cop_result++ = *temp++;
	if (buffer && len > 0)
		while (len--)
			*cop_result++ = *buffer++;
	*cop_result = '\0';
	return (free(line), result);
}

char	*read_line_m(int fd, char *buffer, char *line)
{
	ssize_t	bytes_read;
	size_t	i;

	i = 0;
	while (ft_strchr_m(line, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && ft_strlen_m(line) == 0))
		{
			while (i <= BUFFER_SIZE)
				buffer[i++] = '\0';
			return (free(line), NULL);
		}
		if (bytes_read == 0)
		{
			buffer[bytes_read] = '\0';
			break ;
		}
		buffer[bytes_read] = '\0';
		line = get_line_m(line, buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

void	clean_line_m(char *buffer)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	i = 0;
	while (buffer[len] != '\0')
		buffer[i++] = buffer[len++];
	buffer[i] = '\0';
}
