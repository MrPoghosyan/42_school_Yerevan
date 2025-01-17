/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:58:40 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/03 12:23:49 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
int	main(void)
{
	char	src[] = "Hello, world!";
	char	dest[20];
	unsigned int	len;

	len = ft_strlcpy(dest, src, 10);
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	printf("Source Length: %u\n", len);

	return (0);
}
*/
