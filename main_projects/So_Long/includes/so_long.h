/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:38:42 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/13 18:22:52 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>  //open()
# include <unistd.h> //close(), read(), write()
# include <stdlib.h> //malloc(), free(), exit()
# include <stdio.h>  //perror()
//# include <string.h> //strerror()

# include "../libs/Libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/gnl/get_next_line.h"

// Linux keycodes (X11)
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define Q 113
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define Q 113

# define TILE_SIZE 64
# define WALL 0
# define FLOOR 1
# define COLLECT 2
# define EXIT 3
# define PLAYER 4

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		players;
	int		player_x;
	int		player_y;
	int		allow_exit;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*textures[5]; // wall, floor, collect, exit, player
	t_map	map;
	int		moves;
	int		total_collectibles;
	int		collected;
}	t_game;

// Validation prototypes
int		validate_map(char *file, t_map *map);
int		check_file_extension(char *file);
int		check_file_exists(char *file);
int		read_map_file(char *file, t_map *map);
int		validate_map_contents(t_map *map);
int		is_surrounded_by_walls(t_map *map);
int		has_valid_path(t_map *map);

// Utility prototypes
void	free_arr(char **arr);
void	exit_with_error(const char *message, t_map *map);
void	exit_game(t_game *game, const char *msg);
int		count_characters(t_map *map, char c);
int		close_game(t_game *game);
void	render_cell(t_game *game, char cell, int x, int y);
void	render_layered(t_game *game, int x, int y, int top_texture);

/* Graphics prototypes */
int		init_mlx(t_game *game);
void	load_textures(t_game *game);
void	render_map(t_game *game);

// Player
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);

#endif
