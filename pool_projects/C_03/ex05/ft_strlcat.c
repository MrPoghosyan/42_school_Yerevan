/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:41:06 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/05 18:39:33 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && (dest_len + i + 1) < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if ((dest_len + i) < size)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
	char dest[20] = "Hello";
	char src[] = " World";
	unsigned int size = 15;

	unsigned int result = ft_strlcat(dest, src, size);

	printf("Resulting string: %s\n", dest);
	printf("Returned length: %u\n", result);

	return (0);
}
*/
