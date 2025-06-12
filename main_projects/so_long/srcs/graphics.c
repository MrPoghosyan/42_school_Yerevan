#include "../includes/so_long.h"

// init_mlx
int init_mlx(t_game *game)
{
    game->mlx = mlx_init();
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
    int i = 0;
    while (i < 5)
        game->textures[i++] = NULL;
    return (1);
}

// load_textures
void load_textures(t_game *game)
{
    int width;
    int height;
    int i;

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
            exit_with_error("Failed to load texture!", &game->map);
        ++i;
    }
}
// srcs/graphics.c
void test_render(t_game *game)
{
    int x = 0;
    int y = 0;

    mlx_put_image_to_window(game->mlx, game->win, game->textures[WALL], x, y);
    mlx_put_image_to_window(game->mlx, game->win, game->textures[FLOOR], x + TILE_SIZE, y);
    mlx_put_image_to_window(game->mlx, game->win, game->textures[COLLECT], x + 2*TILE_SIZE, y);
    mlx_put_image_to_window(game->mlx, game->win, game->textures[EXIT], x + 3*TILE_SIZE, y);
    mlx_put_image_to_window(game->mlx, game->win, game->textures[PLAYER], x + 4*TILE_SIZE, y);
}
