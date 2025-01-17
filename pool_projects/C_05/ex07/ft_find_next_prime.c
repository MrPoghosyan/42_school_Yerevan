/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:41:45 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/09 19:53:56 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
/*
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_find_next_prime(0));    //  2
    printf("%d\n", ft_find_next_prime(1));    //  2
    printf("%d\n", ft_find_next_prime(2));    //  2
    printf("%d\n", ft_find_next_prime(3));    //  3
    printf("%d\n", ft_find_next_prime(4));    //  5
    printf("%d\n", ft_find_next_prime(10));   //  11
    printf("%d\n", ft_find_next_prime(17));   //՝ 17
    printf("%d\n", ft_find_next_prime(18));   //  19
    printf("%d\n", ft_find_next_prime(100));  //  101
    return 0;
}
*/
