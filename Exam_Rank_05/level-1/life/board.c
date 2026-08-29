#include "life.h"

int	create_board(t_board *board, int width, int height)
{
	board->width = width;
	board->height = height;
	board->cells = calloc((size_t)width * (size_t)height, sizeof(char));
	if (!board->cells)
		return (1);
	return (0);
}

void	free_board(t_board *board)
{
	free(board->cells);
}

char	get_cell(t_board *board, int x, int y)
{
	if (x < 0 || x >= board->width || y < 0 || y >= board->height)
		return (0);
	return (board->cells[y * board->width + x]);
}

void	set_cell(t_board *board, int x, int y, char value)
{
	if (x < 0 || x >= board->width || y < 0 || y >= board->height)
		return ;
	board->cells[y * board->width + x] = value;
}
