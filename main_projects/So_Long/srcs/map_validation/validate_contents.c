/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   validate_contents.c                                :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/12 13:04:58 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/13 11:52:50 by vapoghos         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->grid[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

static int	has_valid_characters(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!ft_strchr("01CEP", map->grid[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	has_valid_objects(t_map *map)
{
	if (map->players != 1)
	{
		ft_printf("Error: Found %d players (need 1).\n", map->players);
		return (0);
	}
	if (map->exits != 1)
	{
		ft_printf("Error: Found %d exit (need 1).\n", map->exits);
		return (0);
	}
	if (map->collectibles < 1)
	{
		ft_printf("Error: No collectibles found.\n");
		return (0);
	}
	return (1);
}

int	validate_map_contents(t_map *map)
{
	if (!is_rectangular(map))
	{
		ft_printf("Error: Map is not rectangular.\n");
		return (0);
	}
	if (!has_valid_characters(map))
	{
		ft_printf("Error: Invalid characters in map.\n");
		return (0);
	}
	if (!is_surrounded_by_walls(map))
	{
		ft_printf("Error: Map not surrounded by walls.\n");
		return (0);
	}
	map->players = count_characters(map, 'P');
	map->exits = count_characters(map, 'E');
	map->collectibles = count_characters(map, 'C');
	if (!has_valid_objects(map))
	{
		ft_printf("Error: Invalid objects in map.\n");
		return (0);
	}
	return (1);
}
