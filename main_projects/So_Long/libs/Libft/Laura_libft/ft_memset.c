/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:34:32 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/06 14:53:48 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)

{
	unsigned char	*x;

	x = (unsigned char *) b;
	while (len > 0)
	{
		*x = (unsigned char)c;
		x++;
		len--;
	}
	return (b);
}
/*
int	main(void)
{
	char	arr[5];
	
	ft_memset( arr, 97, 4);
	printf("%s", arr);
}*/
