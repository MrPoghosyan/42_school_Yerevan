/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:37:37 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/02 20:16:50 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	tmp;

	index = 0;
	while (index < size / 2)
	{
		tmp = tab[index];
		tab[index] = tab[size - index - 1];
		tab[size - index - 1] = tmp;
		index++;
	}
}
/*
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    ft_rev_int_tab(arr, size);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}*/
