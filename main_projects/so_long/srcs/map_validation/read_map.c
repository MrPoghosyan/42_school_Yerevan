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
    if (!line  || (ft_strlen(line) < 3))
        return (close(fd), height);
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
    size_t  len;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    line = get_next_line(fd);
    if (!line)
        return (close(fd), 0);
    while (line != NULL) 
    {
        len = ft_strlen(line);
        if (len > 0 && line[len-1] == '\n')
            line[--len] = '\0';
        if (len > 0 && line[len-1] == '\r')
            line[--len] = '\0';
        map->grid[i++] = line;
        line = get_next_line(fd);
    }
    map->grid[i] = NULL;
    close(fd);
    return (1);
}

int read_map_file(char *file, t_map *map)
{
    map->height = get_map_height(file);
    if (map->height < 3)
        return (0);
    map->grid = (char **)malloc(sizeof(char *) * (map->height +1));
    if (!map->grid)
        return (0);
    if (!fill_map_grid(map, file))
    {
        free_arr(map->grid);
        return (0);
    }
    map->width = ft_strlen(map->grid[0]);
    if (map->width < 3)
        return (free_arr(map->grid), 0);
    return (1);
}
