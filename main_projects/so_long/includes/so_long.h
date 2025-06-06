#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>  //open()
# include <unistd.h> //close(), read(), write()
# include <stdlib.h> //malloc(), free(), exit()
# include <stdio.h>  //perror()
# include <string.h> //strerror()

# include "../libs/Libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/gnl/get_next_line.h"

# define TILE_SIZE 64

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
}	t_map;

// srcs/game_init.c
typedef struct s_game
{
	t_map	map;
	int		moves;
	void	*mlx;
	void	*win;
	void	*textures[5]; // wall, empty, collect, exit, player
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
void	free_map(t_map *map);
void	exit_with_error(char *message, t_map *map);
int		count_characters(t_map *map, char c);

#endif
