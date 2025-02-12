/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:53:45 by vapoghos          #+#    #+#             */
/*   Updated: 2025/02/06 13:51:00 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*result;
	char	*cop_result;
	char	*temp;

	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	cop_result = result;
	if (s1)
	{
		temp = s1;
		while (*s1)
			*cop_result++ = *s1++;
		free(temp);
	}
	while (*s2)
		*cop_result++ = *s2++;
	*cop_result = '\0';
	return (result);
}

char	*extract_line(char *remainder)
{
	char	*extract;
	char	*result;
	size_t	len;

	len = 0;
	while (*(remainder + len) && *(remainder + len) != '\n')
		++len;
	if (*(remainder + len) == '\n')
		++len;
	extract = (char *)malloc((len + 1) * sizeof(char));
	if (!extract)
		return (NULL);
	result = extract;
	while (len--)
		*extract++ = *remainder++;
	*extract = '\0';
	return (result);
}

char	*save_remainder(char *remainder)
{
	char	*newline;
	char	*new_remainder;
	char	*str;
	size_t	len;

	newline = ft_strchr(remainder, '\n');
	if (!newline || !*(newline +1))
	{
		free(remainder);
		return (NULL);
	}
	len = ft_strlen(newline +1);
	str = (char *)malloc((len +1) * sizeof(char));
	if (!str)
		return (free(remainder), NULL);
	new_remainder = str;
	if (*newline == '\n')
		newline++;
	while (*newline)
		*str++ = *newline++;
	*str = '\0';
	free(remainder);
	return (new_remainder);
}
