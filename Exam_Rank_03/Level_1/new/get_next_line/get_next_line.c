/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erazumov <erazumov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:56:00 by erazumov          #+#    #+#             */
/*   Updated: 2025/07/18 15:42:59 by erazumov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
    int i = 0;
    if (!s)
        return NULL;
    while (s[i])
    {
        if (s[i] == (char)c)
            return (s + i);
        i++;
    }
    if (s[i] == (char)c)
        return (s + i);
    return NULL;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest || !src)
		return NULL;
	while (n-- > 0)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	ret = 0;

	if (!s || !*s)
		return ret;
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	if (*s1)
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp [size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	if (!dest && !src)
		return NULL;
	if (dest > src)
		return (ft_memcpy(dest, src, n));
	else if (dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	char	*tmp = ft_strchr(b, '\n');
	int	read_ret;

	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret <= 0)
		{
			if (read_ret == -1)
				return (free(ret), NULL);
			if (ret && *ret)
				return ret;
			return (free(ret), NULL);
		}
		b[read_ret] = 0;
		tmp = ft_strchr(b, '\n');
	}
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	ft_memmove(b, tmp +1, ft_strlen(tmp +1) +1);
	return (ret);
}
