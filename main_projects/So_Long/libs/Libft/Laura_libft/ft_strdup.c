/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:59 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/06 19:10:12 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dup = (char *)malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int main()
{
	const char *src = "Hello";
	char *dup = ft_strdup(src);

	if (dup)
	{
		printf("%s\n", dup);
	}
	else
	{
		printf("no mem");
	}
	return (0);
}*/
