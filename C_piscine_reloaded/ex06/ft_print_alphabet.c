/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:48:49 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/12 12:04:16 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

void	ft_print_alphabet(void)
{
	char	a;

	a = 'a';
	while (a <= 'z')
		ft_putchar (a++);
}
/*
int main(void)
{
	ft_print_alphabet();

	write (1, "\n", 1);
	return (0);
}*/
