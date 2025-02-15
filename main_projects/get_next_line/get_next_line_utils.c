/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/06 12:53:45 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/02/11 14:40:48 by vapoghos		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s ++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*get_lin(char *line, char *buffer)
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
	result = (char *)malloc(ft_strlen(line) + len + 1);
	if (!result)
		return (free(line), NULL);
	cop_result = result;
	temp = line;
	if (temp)
		while (*temp)
			*cop_result++ = *temp++;
	if (buffer)
		while (len--)
			*cop_result++ = *buffer++;
	*cop_result = '\0';
	return (free(line), result);
}

char	*read_line(int fd, char *buffer, char *line)
{
	ssize_t		bytes_read;

	while (ft_strchr(line, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && ft_strlen(line) == 0))
			return (buffer[0] = '\0', free(line), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = get_lin(line, buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

void	clean_line(char *buffer)
{
	char	*newline;
	size_t	len;

	len = 0;
	while (*(buffer + len) != '\n' && *(buffer + len) != '\0')
		len++;
	newline = buffer + len;
	if (!newline || !*(newline + 1))
	{
		*buffer = '\0';
		return ;
	}
	if (*newline == '\n')
		newline++;
	while (*newline)
		*buffer++ = *newline++;
	*buffer = '\0';
}
