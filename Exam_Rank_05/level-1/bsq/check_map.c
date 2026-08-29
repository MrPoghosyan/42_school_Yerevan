#include "bsq.h"

static int	line_width(t_map *map, int i)
{
	int	len;

	len = map->lengths[i];
	if (map->grid[i][len - 1] == '\n')
		len--;
	return (len);
}

int	check_grid(t_map *map)
{
	int	i;
	int	j;
	int	width;

	width = line_width(map, 0);
	if (width <= 0)
		return (1);
	map->cols = width;
	i = 0;
	while (i < map->rows)
	{
		if (line_width(map, i) != width)
			return (1);
		if (i < map->rows - 1 && map->grid[i][map->lengths[i] - 1] != '\n')
			return (1);
		j = 0;
		while (j < width)
		{
			if (map->grid[i][j] != map->empty
				&& map->grid[i][j] != map->obstacle
				&& map->grid[i][j] != map->full)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
