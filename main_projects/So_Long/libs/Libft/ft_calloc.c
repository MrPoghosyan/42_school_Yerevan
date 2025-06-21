/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:29:03 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/27 14:17:54 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ret_pt;
	unsigned char	*ptr;
	size_t			total_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	ret_pt = (char *)malloc(total_size);
	if (!ret_pt)
		return (NULL);
	ptr = (unsigned char *)ret_pt;
	while (total_size--)
	{
		*ptr++ = 0;
	}
	return (ret_pt);
}
