#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_ZIZE
#  define BUFER_SIZE 10
# endif

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);

#endif
