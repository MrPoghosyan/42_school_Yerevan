/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:17:52 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/02 20:29:12 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
/*
#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);

int main()
{
    int arr[] = {5, 2, 9, 1, 3};
    int size = 5;

    ft_sort_int_tab(arr, size);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}*/
