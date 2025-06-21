/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:48:07 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/10 22:42:34 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	inset(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && inset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && inset(s1[end - 1], set))
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + start, end - start);
	trimmed[end - start] = '\0';
	return (trimmed);
}
/*
int main()
{
	char x[] = "Hi idiots";
	char c[] = "s";
	char *res;

	res = ft_strtrim(x, c);
	printf("%s\n", res);
	free(res);
	return (0);
}*/
