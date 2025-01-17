/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:48:27 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/09 14:22:30 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	pah;

	pah = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		pah *= nb;
		power--;
	}
	return (pah);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%d \n", ft_iterative_power(5, 0));
	printf("%d \n", ft_iterative_power(5, 1));
	printf("%d \n", ft_iterative_power(5, 2));
	printf("%d \n", ft_iterative_power(0, 0));
	printf("%d \n", ft_iterative_power(4, -5));
	return 0;
}*/
