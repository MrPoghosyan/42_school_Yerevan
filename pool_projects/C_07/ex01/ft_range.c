/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:48:50 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/17 11:51:40 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	size;

	if (min >= max)
		return (NULL);
	size = max - min;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (min < max)
		arr[i++] = min++;
	return (arr);
}
/*
#include <stdio.h>

int main(void)
{
    int *range;
    int i;
    int size;

    range = ft_range(7, 5);
    if (!range)
    {
        printf("NULL\n");
        return (0);
    }

    size = 5 - 0;
    for (i = 0; i < size; i++)
        printf("%d ", range[i]);
    printf("\n");

    free(range);
    return (0);
}*/
