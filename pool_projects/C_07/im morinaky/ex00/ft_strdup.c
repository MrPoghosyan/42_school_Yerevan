/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:42:03 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/17 11:44:48 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
#include <stdio.h>

int main(void)
{
    char *original = "Hello, world!";
    char *copy = ft_strdup(original);

    if (copy == NULL)
    {
        printf("Memory allocation failed\\n");
        return (1);
    }

    printf("Original: %s\n", original);
    printf("Copy: %s\n", copy);

    free(copy);

    return (0);
}*/
