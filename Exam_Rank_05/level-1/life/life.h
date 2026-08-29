#ifndef LIFE_H
# define LIFE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pen
{
	int	x;
	int	y;
	int	drawing;
}	t_pen;

typedef struct s_board
{
	int		width;
	int		height;
	char	*cells;
}	t_board;

int		parse_args(int argc, char **argv, int *width, int *height,
			int *iterations);
int		create_board(t_board *board, int width, int height);
void	free_board(t_board *board);
char	get_cell(t_board *board, int x, int y);
void	set_cell(t_board *board, int x, int y, char value);
void	read_input(t_board *board);
void	run_iterations(t_board *board, int iterations);
void	print_board(t_board *board);

#endif
