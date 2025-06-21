/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:03:19 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/06 15:00:06 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	sl;
	size_t	dl;

	i = 0;
	sl = 0;
	dl = 0;
	while (dl < dstsize && dst[dl])
		dl++;
	sl = ft_strlen(src);
	if (dstsize <= dl)
		return (dstsize + sl);
	while ((src[i]) && (dl + i) < (dstsize - 1))
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}
/*
int main()
{
	char		x[6] = "Hello";
	const char	*y = " world";
	char res;

	res = ft_strlcat(x,y,10);
	printf("%s", x);
}*/
