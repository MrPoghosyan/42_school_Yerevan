/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/12 13:06:59 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/13 18:46:27 by vapoghos         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	if (argc != 2)
		exit_with_error("Usage: ./so_long <map.ber>", NULL);
	ft_memset(&game, 0, sizeof(t_game));
	game.mlx = NULL;
	game.win = NULL;
	game.moves = 0;
	i = 0;
	while (i < 5)
		game.textures[i++] = NULL;
	validate_map(argv[1], &game.map);
	if (!init_mlx(&game))
		exit_with_error("MLX initialization failed", &game.map);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
