#include "life.h"

void	print_board(t_board *board)
{
	int	x;
	int	y;

	y = 0;
	while (y < board->height)
	{
		x = 0;
		while (x < board->width)
		{
			if (get_cell(board, x, y))
				putchar('O');
			else
				putchar(' ');
			x++;
		}
		putchar('\n');
		y++;
	}
}
