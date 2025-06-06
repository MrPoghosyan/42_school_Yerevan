#include "../../includes/so_long.h"

static int get_map_height(char *file)
{
    int     fd;
    int     height;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (-1);
    height = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (height);
}

static int fill_map_grid(t_map *map, char *file)
{
    int     fd;
    int     i;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    line = get_next_line(fd);
    while (line != NULL) 
    {
        map->grid[i] = line;
        i++;
        line = get_next_line(fd);
    }
    close(fd);
    return (1);
}

int read_map_file(char *file, t_map *map)
{
    map->height = get_map_height(file);
    if (map->height < 3)
        return (0);
    map->grid = (char **)malloc(sizeof(char *) * map->height);
    if (!map->grid)
        return (0);
    if (!fill_map_grid(map, file))
    {
        free_map(map);
        return (0);
    }
    map->width = ft_strlen(map->grid[0]);
    return (1);
}
