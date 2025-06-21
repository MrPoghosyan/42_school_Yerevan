/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:48:48 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/10 22:28:12 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (i < n)
	{
		if (s1[i] == '\0' && s2[i] != '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else if (s2[i] == '\0' && s2[i] != '\0')
		{
			return ((unsigned char) s1[i]);
		}
	}
	return (0);
}
/*
#include <string.h>

int main(void)
{
	char s1[] = "Hehlo kord";
	char s2[] = "Hello w";

	printf("is the difference  ft_str(): %d\n", ft_strncmp(s1,s2, 5));
	printf("is the difference str(): %d\n", strncmp(s1,s2, 5));
	return (0);
}*/
