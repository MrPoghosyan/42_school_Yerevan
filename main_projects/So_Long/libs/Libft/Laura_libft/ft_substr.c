/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:11:50 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/10 22:38:20 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substring;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (NULL);
	ft_memcpy(substring, s + start, len);
	substring[len] = '\0';
	return (substring);
}
/*
int main()
{
	char *s = "Hello dear user!";
	char *x = ft_substr(s, 11, 6);

	printf("%s", x);
	return (0);
}*/
