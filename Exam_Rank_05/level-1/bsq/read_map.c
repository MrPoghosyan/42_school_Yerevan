#include "bsq.h"

int	read_header(FILE *fp, t_map *map)
{
	int	matched;

	matched = fscanf(fp, " %d %c %c %c", &map->rows, &map->empty,
			&map->obstacle, &map->full);
	if (matched != 4 || map->rows <= 0)
		return (1);
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (1);
	(void)fscanf(fp, "%*[^\n]");
	(void)fscanf(fp, "%*c");
	return (0);
}

int	read_grid(FILE *fp, t_map *map)
{
	int		i;
	size_t	cap;
	ssize_t	len;

	map->grid = calloc(map->rows, sizeof(char *));
	map->lengths = calloc(map->rows, sizeof(int));
	if (!map->grid || !map->lengths)
		return (1);
	i = 0;
	while (i < map->rows)
	{
		cap = 0;
		len = getline(&map->grid[i], &cap, fp);
		if (len <= 0)
			return (1);
		map->lengths[i] = (int)len;
		i++;
	}
	return (0);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->rows)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	if (map->lengths)
		free(map->lengths);
}
