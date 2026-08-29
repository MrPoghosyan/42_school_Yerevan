#include "life.h"

int	parse_args(int argc, char **argv, int *width, int *height,
		int *iterations)
{
	if (argc != 4)
		return (1);
	*width = atoi(argv[1]);
	*height = atoi(argv[2]);
	*iterations = atoi(argv[3]);
	if (*width <= 0 || *height <= 0 || *iterations < 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_board	board;
	int		width;
	int		height;
	int		iterations;

	if (parse_args(argc, argv, &width, &height, &iterations))
		return (1);
	if (create_board(&board, width, height))
		return (1);
	read_input(&board);
	run_iterations(&board, iterations);
	print_board(&board);
	free_board(&board);
	return (0);
}
