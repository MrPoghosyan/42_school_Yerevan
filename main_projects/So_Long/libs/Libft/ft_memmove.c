/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:22:38 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/21 12:25:07 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	if (dest == src || n == 0)
		return (dest);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if (ptr_dest > ptr_src && ptr_src + n > ptr_dest)
	{
		ptr_dest += n;
		ptr_src += n;
		while (n--)
			*(--ptr_dest) = *(--ptr_src);
	}
	else
	{
		while (n--)
			*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}
