/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:54:20 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/21 12:59:52 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	const char	*src_start;

	src_start = src;
	if (dsize > 0)
	{
		while (--dsize && *src)
		{
			*dst++ = *src++;
		}
		*dst = '\0';
	}
	while (*src++)
		;
	return (src - src_start - 1);
}
