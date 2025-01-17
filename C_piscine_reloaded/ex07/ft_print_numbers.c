/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:22:58 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/12 12:04:56 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

void	ft_print_numbers(void)
{
	char	a;

	a = '0';
	while (a <= '9')
		ft_putchar (a++);
}
/*
int main(void)
{
	ft_print_numbers();

	write (1, "\n", 1);
	return (0);
}*/
