#include "../../includes/so_long.h"

int check_file_extension(char *file)
{
    int len;

    len = ft_strlen(file);
    if (len < 4)
        return (0);
    if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
        return (0);
    return (1);
}

int check_file_exists(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    close(fd);
    return (1);
}
