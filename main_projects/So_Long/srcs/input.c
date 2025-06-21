/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:07:05 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/12 15:38:58 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
		close_game(game);
	else if (keycode == W || keycode == UP)
		move_player(game, 0, -1);
	else if (keycode == S || keycode == DOWN)
		move_player(game, 0, 1);
	else if (keycode == A || keycode == LEFT)
		move_player(game, -1, 0);
	else if (keycode == D || keycode == RIGHT)
		move_player(game, 1, 0);
	return (0);
}
