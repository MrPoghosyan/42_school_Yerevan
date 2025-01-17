/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:24:45 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/08 19:32:35 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	result = 1;
	while (nb != 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
    printf("%d\n",ft_iterative_factorial(5));
    printf("%d\n",ft_iterative_factorial(-5));
    printf("%d\n",ft_iterative_factorial(1));
    printf("%d\n", ft_iterative_factorial(0));
    return 0;
}*/
