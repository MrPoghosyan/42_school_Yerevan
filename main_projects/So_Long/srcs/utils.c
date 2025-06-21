/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/12 13:07:31 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/13 12:49:02 by vapoghos         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_characters(t_map *map, char c)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == c)
			{
				count++;
				if (c == 'P')
				{
					map->player_x = x;
					map->player_y = y;
				}
			}
			x++;
		}
		y++;
	}
	return (count);
}

static void	put_img(t_game *game, int x, int y, int id)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[id], x * TILE_SIZE, y * TILE_SIZE);
}

void	render_layered(t_game *game, int x, int y, int top_texture)
{
	put_img(game, x, y, FLOOR);
	put_img(game, x, y, top_texture);
}

void	render_cell(t_game *game, char cell, int x, int y)
{
	if (cell == '1')
		put_img(game, x, y, WALL);
	else if (cell == '0')
		put_img(game, x, y, FLOOR);
	else if (cell == 'P')
		render_layered(game, x, y, PLAYER);
	else if (cell == 'C')
		render_layered(game, x, y, COLLECT);
	else if (cell == 'E')
		render_layered(game, x, y, EXIT);
}
