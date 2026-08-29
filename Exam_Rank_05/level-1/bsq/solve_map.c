#include "bsq.h"

static int	cell_empty(t_map *map, int i, int j)
{
	return (map->grid[i][j] == map->empty);
}

static int	min3(int a, int b, int c)
{
	if (b < a)
		a = b;
	if (c < a)
		a = c;
	return (a);
}

static void	fill_square(t_map *map, int row, int col, int size)
{
	int	i;
	int	j;

	if (size <= 0)
		return ;
	i = row;
	while (i < row + size)
	{
		j = col;
		while (j < col + size)
		{
			map->grid[i][j] = map->full;
			j++;
		}
		i++;
	}
}

void	solve_map(t_map *map)
{
	int	*dp;
	int	i;
	int	j;
	int	best_size;
	int	best_row;
	int	best_col;

	dp = calloc(map->rows * map->cols, sizeof(int));
	if (!dp)
		return ;
	best_size = 0;
	best_row = 0;
	best_col = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (cell_empty(map, i, j))
			{
				if (i == 0 || j == 0)
					dp[i * map->cols + j] = 1;
				else
					dp[i * map->cols + j] = min3(dp[(i - 1) * map->cols + j],
							dp[i * map->cols + (j - 1)],
							dp[(i - 1) * map->cols + (j - 1)]) + 1;
				if (dp[i * map->cols + j] > best_size)
				{
					best_size = dp[i * map->cols + j];
					best_row = i - best_size + 1;
					best_col = j - best_size + 1;
				}
			}
			j++;
		}
		i++;
	}
	free(dp);
	fill_square(map, best_row, best_col, best_size);
}
