// srcs/main.c (exempliar)
#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    
    if (argc != 2)
        exit_with_error("Usage: ./so_long <map.ber>", NULL);
    ft_memset(&game, 0, sizeof(t_game));
    game.mlx = NULL;
    game.win = NULL;
    for (int i = 0; i < 5; i++)
        game.textures[i] = NULL;
    validate_map(argv[1], &game.map);
    if (!init_mlx(&game))
        exit_with_error("MLX initialization failed", &game.map);
    load_textures(&game);
    test_render(&game);
    mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);
    mlx_loop(game.mlx);
    return (0);
}
