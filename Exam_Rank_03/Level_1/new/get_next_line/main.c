#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return (1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        perror("fopen");
        return (1);
    }

    int fd = fileno(fp);
    char *line;
    int line_num = 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", line_num++, line);
        free(line);
    }

    fclose(fp);
    return (0);
}
