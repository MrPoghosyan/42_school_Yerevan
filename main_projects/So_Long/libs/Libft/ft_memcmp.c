/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:46:57 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/21 13:54:35 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	ptr_s1 = (const unsigned char *)s1;
	ptr_s2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*ptr_s1 != *ptr_s2)
		{
			return (*ptr_s1 - *ptr_s2);
		}
		ptr_s1++;
		ptr_s2++;
	}
	return (0);
}
