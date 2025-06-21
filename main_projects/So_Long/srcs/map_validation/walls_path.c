/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   walls_path.c                                       :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/12 13:05:13 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/13 18:26:06 by vapoghos         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_surrounded_by_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (y == 0 || y == map->height - 1)
		{
			x = 0;
			while (x < map->width)
			{
				if (map->grid[y][x] != '1')
					return (0);
				x++;
			}
		}
		else if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static void	flood_fill(t_map *map, int x, int y, int *visited)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (visited[y * map->width + x])
		return ;
	if (map->grid[y][x] == '1')
		return ;
	if (!map->allow_exit && map->grid[y][x] == 'E')
		return ;
	visited[y * map->width + x] = 1;
	flood_fill(map, x + 1, y, visited);
	flood_fill(map, x - 1, y, visited);
	flood_fill(map, x, y + 1, visited);
	flood_fill(map, x, y - 1, visited);
}

static int	check_collectibles(t_map *map, int *visited)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < map->width * map->height)
	{
		y = i / map->width;
		x = i % map->width;
		if (map->grid[y][x] == 'C' && !visited[i])
			return (0);
		i++;
	}
	return (1);
}

static int	check_exit(t_map *map, int *visited)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < map->width * map->height)
	{
		y = i / map->width;
		x = i % map->width;
		if (map->grid[y][x] == 'E' && !visited[i])
			return (0);
		i++;
	}
	return (1);
}

int	has_valid_path(t_map *map)
{
	int	*visited;
	int	valid;

	visited = (int *)ft_calloc(map->width * map->height, sizeof(int));
	if (!visited)
		return (0);
	map->allow_exit = 0;
	flood_fill(map, map->player_x, map->player_y, visited);
	valid = check_collectibles(map, visited);
	free(visited);
	if (!valid)
		return (0);
	visited = (int *)ft_calloc(map->width * map->height, sizeof(int));
	if (!visited)
		return (0);
	map->allow_exit = 1;
	flood_fill(map, map->player_x, map->player_y, visited);
	valid = check_exit(map, visited);
	free(visited);
	return (valid);
}
