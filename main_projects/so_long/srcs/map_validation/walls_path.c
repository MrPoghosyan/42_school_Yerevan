#include "../../includes/so_long.h"

int is_surrounded_by_walls(t_map *map)
{
    int x;
    int y;

    y = 0;
    while (y < map->height)
    {
        if (y == 0 || y == map->height - 1)
        {
            x = 0;
            while (x < map->width)
            {
                if (map->grid[y][x] != '1')
                    return (0);
                x++;
            }
        }
        else if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
            return (0);
        y++;
    }
    return (1);
}

static void flood_fill(t_map *map, int x, int y, int *visited)
{
    if (x < 0 || y < 0 || x >= map->width || y >= map->height)
        return;
    if (visited[y * map->width + x] || map->grid[y][x] == '1')
        return;
    visited[y * map->width + x] = 1;
    flood_fill(map, x + 1, y, visited);
    flood_fill(map, x - 1, y, visited);
    flood_fill(map, x, y + 1, visited);
    flood_fill(map, x, y - 1, visited);
}

int has_valid_path(t_map *map)
{
    int *visited;
    int i;
    int valid;
    int x;
    int y;

    visited = (int *)ft_calloc(map->width * map->height, sizeof(int));
    if (!visited)
        return (0);
    flood_fill(map, map->player_x, map->player_y, visited);
    valid = 1;
    i = 0;
    while (i < map->width * map->height)
    {
        y = i / map->width;
        x = i % map->width;
        if ((map->grid[y][x] == 'C' || map->grid[y][x] == 'E') && !visited[i])
            valid = 0;
        i++;
    }
    free(visited);
    return (valid);
}
