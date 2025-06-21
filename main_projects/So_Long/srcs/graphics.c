/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/12 13:06:13 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/13 12:21:02 by vapoghos         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_textures(t_game *game)
{
	int	width;
	int	height;
	int	i;

	game->textures[WALL] = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->textures[FLOOR] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	game->textures[COLLECT] = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->textures[EXIT] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	game->textures[PLAYER] = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	i = 0;
	while (i < 5)
	{
		if (!game->textures[i])
			close_game(game);
		++i;
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_cell(game, game->map.grid[y][x], x, y);
			x++;
		}
		y++;
	}
}
