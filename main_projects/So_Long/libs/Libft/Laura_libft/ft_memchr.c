/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:32:21 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/06 14:33:50 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		ch;

	src = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*src == ch)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
/*i
int main()
{
	char str[] = "Hello";
	char *result = (char *)ft_memchr(str, 'o', ft_strlen(str));
	
	printf("%p\n", &result);
	
	return (0);
}*/
