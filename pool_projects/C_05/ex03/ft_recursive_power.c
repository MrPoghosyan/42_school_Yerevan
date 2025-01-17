/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:48:34 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/09 14:17:13 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>

int main(void)
{
	printf("2^3 = %d\n", ft_recursive_power(2, 3));	
	printf("5^0 = %d\n", ft_recursive_power(5, 0));
	printf("3^-1 = %d\n", ft_recursive_power(3, -1));
	printf("0^0 = %d\n", ft_recursive_power(0, 0));
	return 0;
}*/
