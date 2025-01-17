/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:13:05 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/05 18:57:36 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, char start, char middle, char end)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar(start);
		else if (col == x - 1)
			ft_putchar(end);
		else
			ft_putchar(middle);
		col++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	if (x < 0 && y < 0)
		return ;
	row = 0;
	while (row < y)
	{
		if (row == 0)
			print_line(x, 'o', '-', 'o');
		else if (row == y - 1)
			print_line(x, 'o', '-', 'o');
		else
			print_line(x, '|', ' ', '|');
		row++;
	}
}
