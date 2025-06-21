/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:16:57 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/11 20:20:00 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	size_t	total;
	void	*ptr;
	size_t	i;

	if (count == 0 || size == 0)
		return (malloc(0));
	total = count * size;
	if (count != 0 && total / count != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}
/*
int main()
{
	int *arr;
	int i = 0;

	arr = (int *)ft_calloc(5, sizeof(int));
	while (i < 5)
	{
		printf("%d", arr[i]);
		i++;
	}
	free(arr);
	return(0);
}*/
