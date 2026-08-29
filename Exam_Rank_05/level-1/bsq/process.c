#include "bsq.h"

int	process_stream(FILE *fp)
{
	t_map	map;

	map.grid = NULL;
	map.lengths = NULL;
	if (read_header(fp, &map))
	{
		fputs("map error\n", stderr);
		return (1);
	}
	if (read_grid(fp, &map) || check_grid(&map))
	{
		free_map(&map);
		fputs("map error\n", stderr);
		return (1);
	}
	solve_map(&map);
	print_map(&map);
	free_map(&map);
	return (0);
}
