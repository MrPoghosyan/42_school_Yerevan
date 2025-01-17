/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:25:45 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/05 18:36:06 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*pah;

	pah = dest;
	while (*pah != '\0')
	{
		pah++;
	}
	while (*src != '\0' && nb > 0)
	{
		*pah = *src;
		pah++;
		src++;
		nb--;
	}
	*pah = '\0';
	return (dest);
}
/*
#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main() {
    char dest[50] = "Hello, ";
    char src[] = "World!";

    printf("Before strncat: %s\n", dest);
    ft_strncat(dest, src, 3);  // Կցում ենք միայն առաջին 3 սիմվոլները։
    printf("After strncat: %s\n", dest);

    return 0;
}
*/
