#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return(perror("open"), 1);

	dprintf(fd, "Writing to fd: %d\n", fd);//write to file.
	close(fd);
	return (0);
}
