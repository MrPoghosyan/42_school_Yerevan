/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/12 13:07:50 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/13 18:48:09 by vapoghos         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_mlx(t_game *game)
{
	int	i;

	game->mlx = mlx_init();
	i = 0;
	while (i < 5)
		game->textures[i++] = NULL;
	load_textures(game);
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx,
			game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE,
			"so_long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (0);
	}
	return (1);
}
