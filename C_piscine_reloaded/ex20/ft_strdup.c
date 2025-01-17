/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:41:02 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/09 12:02:55 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*s2;
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	s2 = (char *)malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = src[i];
		i++;
	}
	s2[len] = '\0';
	return (s2);
}
/*
#include <stdio.h>

int main() {
    char *original = "Hello, World!";
    char *copy = ft_strdup(original);

    if (copy == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Original: %s\n", original);
    printf("Copy: %s\n", copy);

    free(copy);

    return 0;
}*/
