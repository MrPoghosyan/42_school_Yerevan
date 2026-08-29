#include "bsq.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		fputs(map->grid[i], stdout);
		if (map->grid[i][map->lengths[i] - 1] != '\n')
			fputs("\n", stdout);
		i++;
	}
}
