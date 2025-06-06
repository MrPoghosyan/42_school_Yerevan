#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_map map;

    if (argc != 2)
    {
        ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
        return (1);
    }
    
    ft_memset(&map, 0, sizeof(t_map));
    validate_map(argv[1], &map);
    ft_printf("Map is valid!\n");
    free_map(&map);
    return (0);
}
