/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:32:32 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/09 18:43:54 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char **c)
{
	int	count;

	count = 0;
	while (c[count] != NULL)
		count++;
	return (count);
}

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	count;
	int	size;

	size = ft_len (tab);
	count = 0;
	while (size > 0)
	{
		if (f(*tab) == 1)
			count++;
		tab++;
		size--;
	}
	return (count);
}
/*
#include <stdio.h>

int starts_with_a(char *str)
{
    return (str[0] == 'A' || str[0] == 'a');
}

int main()
{
    char *tab[] = {"Apple", "Banana", "Avocado", "Orange", NULL};
    int count = ft_count_if(tab, starts_with_a);
    printf("Number of strings starting with 'A': %d\n", count);
    return 0;
}*/
