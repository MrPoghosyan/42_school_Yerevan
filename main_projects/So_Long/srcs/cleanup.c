/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/12 13:09:20 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/13 12:37:12 by vapoghos         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * Frees a NULL-terminated array of strings.
 */
void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

/**
 * Prints an error message and exits the program.
 * Frees the map grid if provided.
 */
void	exit_with_error(const char *message, t_map *map)
{
	if (message)
		ft_printf("Error\n%s\n", message);
	if (map && map->grid)
		free_arr(map->grid);
	exit(EXIT_FAILURE);
}

/**
 * Cleans up all resources and exits the program.
 * If msg is non-NULL, prints it as an error message before exit.
 */
static void	err_mes(const char *msg)
{
	if (msg)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

void	exit_game(t_game *game, const char *msg)
{
	int	i;

	if (msg)
		ft_printf("Error\n%s\n", msg);
	if (game)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		i = 0;
		while (i < 5)
		{
			if (game->textures[i])
				mlx_destroy_image(game->mlx, game->textures[i]);
			i++;
		}
		if (game->map.grid)
			free_arr(game->map.grid);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	err_mes(msg);
}

/**
 * Callback for window close event.
 */
int	close_game(t_game *game)
{
	exit_game(game, NULL);
	return (0);
}
