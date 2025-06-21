/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:29:45 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/13 17:59:03 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	handle_collectible(t_game *game, int x, int y)
{
	game->map.grid[y][x] = '0';
	game->collected++;
}

static void	update_player_position(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures[FLOOR],
		game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->textures[PLAYER],
		x * TILE_SIZE, y * TILE_SIZE);
	game->map.player_x = x;
	game->map.player_y = y;
}

static int	handle_exit_tile(t_game *game)
{
	if (game->collected == game->map.collectibles)
	{
		ft_printf("🎉 You win!\n");
		close_game(game);
		return (1);
	}
	else
	{
		ft_printf("❗Collect everything first!\n");
		return (0);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->map.player_x + dx;
	new_y = game->map.player_y + dy;
	tile = game->map.grid[new_y][new_x];
	if (tile == '1')
		return ;
	if (tile == 'C')
		handle_collectible(game, new_x, new_y);
	if (tile == 'E')
	{
		if (!handle_exit_tile(game))
			return ;
	}
	update_player_position(game, new_x, new_y);
	game->moves++;
	ft_printf("Move: %d\n", game->moves);
}
