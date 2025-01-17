/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:21:32 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/05 18:35:09 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*pah;

	pah = dest;
	while (*pah != '\0')
		pah++;
	while (*src != '\0')
	{
		*pah = *src;
		pah++;
		src++;
	}
	*pah = '\0';
	return (dest);
}
/*
#include <stdio.h>

char *ft_strcat(char *dest, char *src);

int main() {
    char dest[50] = "Hello, ";
    char src[] = "World!";

    printf("Before strcat: %s\n", dest);
    ft_strcat(dest, src);
    printf("After strcat: %s\n", dest);

    return 0;
}
*/
