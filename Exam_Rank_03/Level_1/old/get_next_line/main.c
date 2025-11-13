#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char *get_next_line(int fd);

int main(void)
{
	char *line;

	int fd = open("get_next_line.h", O_RDONLY);
	if (fd == -1)
		return 1;

	for (int i = 0; i < 18; ++i)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}
