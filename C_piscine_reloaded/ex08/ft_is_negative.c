/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:29:09 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/12 12:05:25 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar ('N');
	else
		ft_putchar ('P');
}
/*
int main(void)
{
	ft_is_negative(0);
	ft_is_negative(5);
	ft_is_negative(-5);

	return 0;
}*/
