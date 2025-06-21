/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:07:38 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/06 15:32:49 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	const char		*last;

	last = NULL;
	ch = (unsigned char) c;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			last = s;
		}
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return ((char *)last);
}
/*
int main() {
    const char *str = "Hello, World!";
    char *result = ft_strrchr(str, 'o');

    if (result) {
        printf("Last: %s\n", result);
    } else {
        printf("Char 'o' not found\n");
    }

    return 0;
}*/
