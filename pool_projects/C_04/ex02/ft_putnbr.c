/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:19:43 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/05 12:45:15 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	pah;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	pah = nb % 10 + '0';
	write(1, &pah, 1);
}
/*
int	main(void)
{
	ft_putnbr(42); 
	write(1, "\n", 1);
	ft_putnbr(-12345); 
	write(1, "\n", 1);
	ft_putnbr(0); 
	write(1, "\n", 1);
	ft_putnbr(-2147483648); // INT_MIN
	write(1, "\n", 1);
	ft_putnbr(2147483647); // INT_MAX
	write(1, "\n", 1);
	return (0);
}
*/
