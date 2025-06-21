/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:10:29 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/06 20:40:31 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}
/*
int main()
{
    const char *str = "Hello, World!";
    char c = 'o';

    char *result = ft_strchr(str, c);

    if (result) {
        printf(" %s\n", result);
    } else {
        printf("%s not found\n", result);
    }
    return 0;
}*/
