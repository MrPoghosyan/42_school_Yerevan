/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:57:02 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/09 20:19:33 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_solution(int *board)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - i == row - col
			|| board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *board, int col, int *count)
{
	int	row;

	if (col == 10)
	{
		ft_put_solution(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, row, col))
		{
			board[col] = row;
			solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}
/*
int main(void)
{
	ft_ten_queens_puzzle();
	return 0;
}*/
