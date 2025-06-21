/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:42:48 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/21 13:44:44 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	target;

	ptr = (unsigned char *)s;
	target = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == target)
		{
			return ((void *)ptr);
		}
		ptr++;
		n--;
	}
	return (NULL);
}
