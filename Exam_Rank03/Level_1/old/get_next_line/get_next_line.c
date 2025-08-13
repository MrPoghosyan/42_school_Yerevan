#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *stash = NULL;
	char *line = NULL;
	char buffer[BUFFER_SIZE +1];
	ssize_t byte_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(stash, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(stash), NULL);
		if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	line = read_line(stash);
	if (!line)
		return (free(stash), NULL);
	stash = update_stash(stash);
	return (line);
}

int ft_strlen(char *s)
{
	int len = 0;

	if(!s || !*s)
		return (0);
	while (s[len])
		++len;
	return (len);
}

int ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return 1;
		s++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *new_line;
	char *tmp;
	char *tmp1 = s1;

	new_line = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (!new_line)
		return (NULL);
	tmp =new_line;
	if (s1 != NULL)
		while (*s1)
			*tmp++ = *s1++;
	while (s2 && *s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	free(tmp1);
	return (new_line);
}

char *read_line(char *stash)
{
	char *line;
	int len = 0;
	int i = 0;

	if (!stash)
		return (NULL);
	while (stash[len] != '\0' && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = (char *)malloc(len +1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (i < len)
	{
		line[i] = stash[i];
		++i;
	}
	return (line);
}

char *update_stash(char *stash)
{
	char *tmp = stash;
	char *upd_stash = NULL;
	int i = 0;
	int j = 0;

	while (*stash && *stash != '\n')
		stash++;
	if (*stash == '\0')
	{
		free(tmp);
		return (NULL);
	}
	if (*stash == '\n' && *(stash +1) != '\0')
	{
		stash++;
		i = ft_strlen(stash);
	}
	upd_stash = (char *)malloc(i +1);
	if (!upd_stash)
		return (free(tmp), NULL);
	upd_stash[i] = '\0';
	while (j < i)
	{
		upd_stash[j] = stash[j];
		++j;
	}
	free(tmp);
	return (upd_stash);
}
