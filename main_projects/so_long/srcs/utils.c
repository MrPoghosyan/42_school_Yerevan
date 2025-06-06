#include "../includes/so_long.h"

void free_map(t_map *map)
{
    int i;

    if (map->grid)
    {
        i = 0;
        while (i < map->height)
        {
            free(map->grid[i]);
            i++;
        }
        free(map->grid);
    }
}

void exit_with_error(char *message, t_map *map)
{
    ft_printf("Error\n%s\n", message);
    free_map(map);
    exit(1);
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
