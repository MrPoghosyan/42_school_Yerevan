#include "life.h"

static int	count_neighbors(t_board *board, int x, int y)
{
	int	count;
	int	dx;
	int	dy;

	count = 0;
	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			if ((dx != 0 || dy != 0) && get_cell(board, x + dx, y + dy))
				count++;
			dx++;
		}
		dy++;
	}
	return (count);
}

static void	step_once(t_board *board)
{
	t_board	next;
	int		x;
	int		y;
	int		n;

	create_board(&next, board->width, board->height);
	y = 0;
	while (y < board->height)
	{
		x = 0;
		while (x < board->width)
		{
			n = count_neighbors(board, x, y);
			if (n == 3 || (n == 2 && get_cell(board, x, y)))
				set_cell(&next, x, y, 1);
			x++;
		}
		y++;
	}
	free(board->cells);
	board->cells = next.cells;
}

void	run_iterations(t_board *board, int iterations)
{
	int	i;

	i = 0;
	while (i < iterations)
	{
		step_once(board);
		i++;
	}
}
