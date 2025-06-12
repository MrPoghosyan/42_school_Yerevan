#include "../includes/so_long.h"

void free_arr(char **arr)
{
    int i;

    if (!arr)
        return ;
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        arr[i] = NULL;
        ++i;
    }
    free(arr);
    arr = NULL;
}

void exit_with_error(char *message, t_map *map)
{
    ft_printf("Error\n%s\n", message);
    if (map && map->grid)
        free_arr(map->grid);
    exit(1);
}


int close_game(t_game *game)
{
    if (!game)
        exit(1);
    
    // 1. Уничтожение окна
    if (game->mlx && game->win)
        mlx_destroy_window(game->mlx, game->win);
    
    // 2. Освобождение текстур
    if (game->mlx)
    {
        int i = 0;
        while (i < 5)
        {
            if (game->textures[i])
                mlx_destroy_image(game->mlx, game->textures[i]);
            i++;
        }
    }
    
    // 3. Освобождение карты
    if (game->map.grid)
        free_arr(game->map.grid);
    
    // 4. Уничтожение mlx соединения
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    
    exit(0);
    return (0);
}

int count_characters(t_map *map, char c)
{
    int count;
    int y;
    int x;

    count = 0;
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->grid[y][x] == c)
            {
                count++;
                if (c == 'P')
                {
                    map->player_x = x;
                    map->player_y = y;
                }
            }
            x++;
        }
        y++;
    }
    return (count);
}
