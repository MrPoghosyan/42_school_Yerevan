/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:47:02 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/06 14:50:57 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if ((d > s) && (d < s + len))
	{
		d += len;
		s += len;
		while (len--)
			*(--d) = *(--s);
	}
	else
	{
		while (len --)
			*(d++) = *(s++);
	}
	return (dst);
}
/*
int main(void)
{
	char str[] = "Hello, World!";

	ft_memmove(str + 7, str, 5);
	printf("Result: %s", str);

	return 0;
}*/
